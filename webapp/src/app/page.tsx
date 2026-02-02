"use client";

import { useState, useMemo } from "react";
import { useAtCoderData } from "@/hooks/useAtCoderData";
import ContestTable from "@/components/ContestTable";
import StatsCard from "@/components/StatsCard";
import { ContestType } from "@/types";

const TABS: { key: ContestType; label: string; prefix: string }[] = [
  { key: "ABC", label: "ABC", prefix: "ABC " },
  { key: "ARC", label: "ARC", prefix: "ARC " },
  { key: "AGC", label: "AGC", prefix: "AGC " },
  { key: "Other", label: "Other", prefix: "" },
];

const COLUMNS_BY_TYPE: Record<ContestType, string[]> = {
  ABC: ["A", "B", "C", "D", "E", "F", "G", "H"],
  ARC: ["A", "B", "C", "D", "E", "F"],
  AGC: ["A", "B", "C", "D", "E", "F"],
  Other: ["A", "B", "C", "D", "E", "F", "G", "H"],
};

export default function Home() {
  const { tableData, stats, problemModels, loading, error } = useAtCoderData();
  const [activeTab, setActiveTab] = useState<ContestType>("ABC");

  const activeRows = useMemo(
    () => tableData[activeTab] || [],
    [tableData, activeTab]
  );
  const activeColumns = COLUMNS_BY_TYPE[activeTab];
  const activePrefix = TABS.find((t) => t.key === activeTab)?.prefix || "";

  if (error) {
    return (
      <div className="min-h-screen bg-[#0a0a0a] flex items-center justify-center px-4">
        <div className="text-center">
          <p className="text-neutral-400 text-sm font-mono">
            error: {error}
          </p>
        </div>
      </div>
    );
  }

  return (
    <div className="min-h-screen bg-[#0a0a0a] text-neutral-200">
      <header className="border-b border-neutral-800 sticky top-0 z-20 bg-[#0a0a0a]">
        <div className="max-w-6xl mx-auto px-3 sm:px-6 py-3 sm:py-4 flex items-center justify-between">
          <div className="flex items-baseline gap-2 sm:gap-3">
            <h1 className="text-sm sm:text-base font-semibold text-white tracking-tight">
              dzuizz
            </h1>
            <span className="text-[10px] sm:text-xs text-neutral-600 font-mono">
              atcoder
            </span>
          </div>
          <a
            href="https://atcoder.jp/users/dzuizz"
            target="_blank"
            rel="noopener noreferrer"
            className="text-[10px] sm:text-xs text-neutral-500 hover:text-white transition-colors font-mono"
          >
            profile &rarr;
          </a>
        </div>
      </header>

      <main className="max-w-6xl mx-auto px-3 sm:px-6 py-4 sm:py-6">
        {loading ? (
          <div className="flex items-center justify-center py-20">
            <p className="text-neutral-600 text-xs font-mono">
              loading...
            </p>
          </div>
        ) : (
          <>
            <div className="flex gap-6 sm:gap-10 mb-6 sm:mb-8">
              <StatsCard label="Solved" value={stats.totalAC} />
              <StatsCard label="Submissions" value={stats.totalSubmissions} />
              <StatsCard label="Contests" value={stats.contestsParticipated} />
            </div>

            <div className="flex items-center gap-0 mb-3 sm:mb-4">
              {TABS.map((tab) => {
                const count = (tableData[tab.key] || []).reduce(
                  (acc, row) =>
                    acc +
                    Object.values(row.problems).filter((p) => p.solved).length,
                  0
                );
                return (
                  <button
                    key={tab.key}
                    onClick={() => setActiveTab(tab.key)}
                    className={`px-3 sm:px-4 py-1.5 text-[11px] sm:text-xs font-mono transition-colors ${
                      activeTab === tab.key
                        ? "text-white bg-neutral-800"
                        : "text-neutral-500 hover:text-neutral-300"
                    }`}
                  >
                    {tab.label}
                    <span className="ml-1 text-neutral-600">{count}</span>
                  </button>
                );
              })}
            </div>

            <ContestTable
              rows={activeRows}
              columns={activeColumns}
              contestPrefix={activePrefix}
              problemModels={problemModels}
            />
          </>
        )}
      </main>
    </div>
  );
}
