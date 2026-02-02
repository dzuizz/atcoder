"use client";

interface StatsCardProps {
  label: string;
  value: number;
}

export default function StatsCard({ label, value }: StatsCardProps) {
  return (
    <div className="border-l-2 border-neutral-700 pl-3 sm:pl-4">
      <div className="text-2xl sm:text-4xl font-semibold text-white font-mono tabular-nums tracking-tight">
        {value.toLocaleString()}
      </div>
      <div className="text-[11px] sm:text-sm text-neutral-500 uppercase tracking-wider mt-0.5">
        {label}
      </div>
    </div>
  );
}
