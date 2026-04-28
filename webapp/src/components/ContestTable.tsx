"use client";

import { useState } from "react";
import { ContestRow, ProblemModel } from "@/types";

const IS_DEV = process.env.NODE_ENV !== "production";

async function createTemplate(contestId: string, problemIndex: string) {
  const res = await fetch("/api/template", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ contestId, problemIndex }),
  });
  const data = await res.json().catch(() => ({}));
  if (!res.ok) throw new Error(data.error || `HTTP ${res.status}`);
  return data as { ok: true; path: string };
}

interface ContestTableProps {
  rows: ContestRow[];
  columns: string[];
  contestPrefix: string;
  problemModels: Record<string, ProblemModel>;
}

function getDifficultyColor(difficulty: number | undefined): string {
  if (difficulty === undefined) return "text-neutral-600";
  if (difficulty < 400) return "text-neutral-500";
  if (difficulty < 800) return "text-amber-700";
  if (difficulty < 1200) return "text-green-600";
  if (difficulty < 1600) return "text-cyan-500";
  if (difficulty < 2000) return "text-blue-500";
  if (difficulty < 2400) return "text-yellow-500";
  if (difficulty < 2800) return "text-orange-500";
  return "text-red-500";
}

export default function ContestTable({
  rows,
  columns,
  contestPrefix,
  problemModels,
}: ContestTableProps) {
  const [busyKey, setBusyKey] = useState<string | null>(null);
  const [toast, setToast] = useState<string | null>(null);

  const handleInit = async (contestId: string, problemIndex: string) => {
    const key = `${contestId}-${problemIndex}`;
    if (busyKey) return;
    setBusyKey(key);
    try {
      const data = await createTemplate(contestId, problemIndex);
      setToast(`created ${data.path}`);
    } catch (e) {
      setToast(`error: ${e instanceof Error ? e.message : String(e)}`);
    } finally {
      setBusyKey(null);
      setTimeout(() => setToast(null), 3000);
    }
  };

  if (rows.length === 0) {
    return (
      <p className="text-neutral-600 py-8 text-center text-sm">
        No contests found.
      </p>
    );
  }

  const solvedCount = rows.reduce(
    (acc, row) =>
      acc + Object.values(row.problems).filter((p) => p.solved).length,
    0
  );
  const totalCount = rows.reduce(
    (acc, row) => acc + Object.values(row.problems).length,
    0
  );

  return (
    <div>
      <div className="mb-2 text-xs sm:text-sm text-neutral-500 font-mono">
        {solvedCount}/{totalCount} solved
      </div>
      <div className="overflow-x-auto table-scroll border border-neutral-800">
        <table className="w-full border-collapse font-mono text-xs sm:text-sm">
          <thead>
            <tr className="border-b border-neutral-800 bg-neutral-900">
              <th className="px-3 sm:px-4 py-2 sm:py-3 text-left text-neutral-500 font-normal uppercase tracking-wider text-[11px] sm:text-xs sticky left-0 bg-neutral-900 z-10 min-w-[64px] sm:min-w-[88px]">
                #
              </th>
              {columns.map((col) => (
                <th
                  key={col}
                  className="px-1 py-2 sm:py-3 text-center text-neutral-500 font-normal text-xs sm:text-sm w-[44px] sm:w-[56px]"
                >
                  {col}
                </th>
              ))}
            </tr>
          </thead>
          <tbody>
            {rows.map((row, i) => (
              <tr
                key={row.contestId}
                className={`border-b border-neutral-900 hover:bg-neutral-800/50 ${
                  i % 2 === 0 ? "bg-transparent" : "bg-neutral-950"
                }`}
              >
                <td className="px-3 sm:px-4 py-1.5 sm:py-2 sticky left-0 z-10 bg-inherit">
                  <a
                    href={`https://atcoder.jp/contests/${row.contestId}`}
                    target="_blank"
                    rel="noopener noreferrer"
                    className="text-neutral-400 hover:text-white transition-colors text-xs sm:text-sm"
                  >
                    {contestPrefix}
                    {row.contestNumber}
                  </a>
                </td>
                {columns.map((col) => {
                  const problem = row.problems[col];
                  if (!problem) {
                    return (
                      <td key={col} className="py-1.5 sm:py-2 text-center">
                        <span className="text-neutral-800">&middot;</span>
                      </td>
                    );
                  }

                  const model = problemModels[problem.problemId];
                  const difficulty = model?.difficulty;

                  const cellKey = `${row.contestId}-${col.toLowerCase()}`;
                  const isBusy = busyKey === cellKey;
                  return (
                    <td key={col} className="py-1.5 sm:py-2 text-center">
                      <div className="relative inline-block group">
                        <a
                          href={`https://atcoder.jp/contests/${row.contestId}/tasks/${problem.problemId}`}
                          target="_blank"
                          rel="noopener noreferrer"
                          className="inline-flex items-center justify-center w-[36px] h-[28px] sm:w-[48px] sm:h-[34px]"
                        >
                          {problem.solved ? (
                            <span className="inline-flex items-center justify-center w-full h-full bg-green-500/15 text-green-400 text-xs sm:text-sm font-semibold border border-green-500/20">
                              AC
                            </span>
                          ) : (
                            <span
                              className={`inline-flex items-center justify-center w-full h-full text-xs sm:text-sm ${getDifficultyColor(difficulty)}`}
                            >
                              {difficulty !== undefined
                                ? Math.round(difficulty)
                                : "-"}
                            </span>
                          )}
                        </a>
                        {IS_DEV && !problem.solved && (
                          <button
                            type="button"
                            disabled={isBusy}
                            onClick={(e) => {
                              e.preventDefault();
                              e.stopPropagation();
                              handleInit(row.contestId, col.toLowerCase());
                            }}
                            title={`init ${row.contestId}/${col.toLowerCase()}.cpp`}
                            aria-label={`init ${row.contestId}/${col.toLowerCase()}.cpp`}
                            className="absolute -top-2 -right-2 z-20 flex items-center justify-center w-5 h-5 sm:w-6 sm:h-6 rounded-full text-sm sm:text-base leading-none bg-neutral-800 text-neutral-400 border border-neutral-700 opacity-0 group-hover:opacity-100 focus:opacity-100 hover:bg-blue-500/20 hover:text-blue-300 hover:border-blue-500/40 transition-opacity disabled:opacity-50 shadow-md cursor-pointer"
                          >
                            {isBusy ? "…" : "+"}
                          </button>
                        )}
                      </div>
                    </td>
                  );
                })}
              </tr>
            ))}
          </tbody>
        </table>
      </div>
      {toast && (
        <div className="fixed bottom-4 right-4 z-50 px-3 py-2 bg-neutral-900 border border-neutral-700 text-neutral-200 text-xs font-mono shadow-lg max-w-md break-all">
          {toast}
        </div>
      )}
    </div>
  );
}
