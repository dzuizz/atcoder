"use client";

import { useState, useEffect, useMemo } from "react";
import {
  Contest,
  ContestProblem,
  Submission,
  ProblemModel,
  ContestType,
  ContestRow,
} from "@/types";

const USER = "dzuizz";

function proxyUrl(path: string): string {
  return `/api/atcoder?path=${encodeURIComponent(path)}`;
}

async function fetchJSON<T>(url: string): Promise<T> {
  const res = await fetch(url);
  if (!res.ok) throw new Error(`Failed to fetch ${url}: ${res.status}`);
  return res.json();
}

async function fetchAllSubmissions(user: string): Promise<Submission[]> {
  const all: Submission[] = [];
  let fromSecond = 0;
  // eslint-disable-next-line no-constant-condition
  while (true) {
    const batch = await fetchJSON<Submission[]>(
      proxyUrl(`/atcoder-api/v3/user/submissions?user=${user}&from_second=${fromSecond}`)
    );
    if (batch.length === 0) break;
    all.push(...batch);
    fromSecond = batch[batch.length - 1].epoch_second + 1;
    // Respect API rate limits
    await new Promise((r) => setTimeout(r, 1000));
  }
  return all;
}

export function useAtCoderData() {
  const [contests, setContests] = useState<Contest[]>([]);
  const [contestProblems, setContestProblems] = useState<ContestProblem[]>([]);
  const [submissions, setSubmissions] = useState<Submission[]>([]);
  const [problemModels, setProblemModels] = useState<
    Record<string, ProblemModel>
  >({});
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    async function load() {
      try {
        const [contestsData, contestProblemsData, problemModelsData] =
          await Promise.all([
            fetchJSON<Contest[]>(proxyUrl("/resources/contests.json")),
            fetchJSON<ContestProblem[]>(proxyUrl("/resources/contest-problem.json")),
            fetchJSON<Record<string, ProblemModel>>(proxyUrl("/resources/problem-models.json")),
          ]);

        const submissionsData = await fetchAllSubmissions(USER);

        setContests(contestsData);
        setContestProblems(contestProblemsData);
        setSubmissions(submissionsData);
        setProblemModels(problemModelsData);
      } catch (e) {
        setError(e instanceof Error ? e.message : "Failed to load data");
      } finally {
        setLoading(false);
      }
    }
    load();
  }, []);

  const acSet = useMemo(() => {
    const set = new Set<string>();
    for (const sub of submissions) {
      if (sub.result === "AC") {
        set.add(sub.problem_id);
      }
    }
    return set;
  }, [submissions]);

  const contestMap = useMemo(() => {
    const map = new Map<string, Contest>();
    for (const c of contests) {
      map.set(c.id, c);
    }
    return map;
  }, [contests]);

  const problemsByContest = useMemo(() => {
    const map = new Map<string, ContestProblem[]>();
    for (const cp of contestProblems) {
      if (!map.has(cp.contest_id)) {
        map.set(cp.contest_id, []);
      }
      map.get(cp.contest_id)!.push(cp);
    }
    // Sort problems within each contest by index
    for (const [, problems] of map) {
      problems.sort((a, b) => a.problem_index.localeCompare(b.problem_index));
    }
    return map;
  }, [contestProblems]);

  const classifyContest = (contestId: string): ContestType => {
    if (contestId.startsWith("abc")) return "ABC";
    if (contestId.startsWith("arc")) return "ARC";
    if (contestId.startsWith("agc")) return "AGC";
    return "Other";
  };

  const extractNumber = (contestId: string): string => {
    const match = contestId.match(/\d+/);
    return match ? match[0] : contestId;
  };

  const tableData = useMemo(() => {
    const grouped: Record<ContestType, ContestRow[]> = {
      ABC: [],
      ARC: [],
      AGC: [],
      Other: [],
    };

    const contestIds = Array.from(problemsByContest.keys());

    for (const contestId of contestIds) {
      const type = classifyContest(contestId);
      const problems = problemsByContest.get(contestId) || [];
      const row: ContestRow = {
        contestId,
        contestNumber: extractNumber(contestId),
        problems: {},
      };
      for (const p of problems) {
        row.problems[p.problem_index] = {
          problemId: p.problem_id,
          solved: acSet.has(p.problem_id),
        };
      }
      grouped[type].push(row);
    }

    // Sort each group by contest number descending (newest first)
    for (const type of Object.keys(grouped) as ContestType[]) {
      grouped[type].sort((a, b) => {
        const numA = parseInt(a.contestNumber) || 0;
        const numB = parseInt(b.contestNumber) || 0;
        return numB - numA;
      });
    }

    return grouped;
  }, [problemsByContest, acSet]);

  const stats = useMemo(() => {
    const totalAC = acSet.size;
    const totalSubmissions = submissions.length;
    const contestsParticipated = new Set(
      submissions.map((s) => s.contest_id)
    ).size;
    return { totalAC, totalSubmissions, contestsParticipated };
  }, [acSet, submissions]);

  return {
    tableData,
    stats,
    contestMap,
    problemModels,
    loading,
    error,
  };
}
