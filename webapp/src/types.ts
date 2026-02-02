export interface Contest {
  id: string;
  start_epoch_second: number;
  duration_second: number;
  title: string;
  rate_change: string;
}

export interface Problem {
  id: string;
  contest_id: string;
  problem_index: string;
  name: string;
  title: string;
}

export interface ContestProblem {
  contest_id: string;
  problem_id: string;
  problem_index: string;
}

export interface Submission {
  id: number;
  epoch_second: number;
  problem_id: string;
  contest_id: string;
  user_id: string;
  language: string;
  point: number;
  length: number;
  result: string;
  execution_time: number | null;
}

export interface ProblemModel {
  slope?: number;
  intercept?: number;
  variance?: number;
  difficulty?: number;
  discrimination?: number;
  irt_loglikelihood?: number;
  irt_users?: number;
  is_experimental?: boolean;
}

export type ContestType = "ABC" | "ARC" | "AGC" | "Other";

export interface ContestRow {
  contestId: string;
  contestNumber: string;
  problems: { [index: string]: { problemId: string; solved: boolean } };
}
