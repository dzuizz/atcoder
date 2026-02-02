import { NextRequest, NextResponse } from "next/server";

const API_BASE = "https://kenkoooo.com/atcoder";

const ALLOWED_PATHS = [
  "/resources/contests.json",
  "/resources/problems.json",
  "/resources/contest-problem.json",
  "/resources/problem-models.json",
  "/atcoder-api/v3/user/submissions",
];

export async function GET(request: NextRequest) {
  const path = request.nextUrl.searchParams.get("path");
  if (!path) {
    return NextResponse.json({ error: "Missing path parameter" }, { status: 400 });
  }

  const isAllowed = ALLOWED_PATHS.some((p) => path.startsWith(p));
  if (!isAllowed) {
    return NextResponse.json({ error: "Path not allowed" }, { status: 403 });
  }

  try {
    const url = `${API_BASE}${path}`;
    const res = await fetch(url, {
      headers: { "Accept": "application/json" },
    });

    if (!res.ok) {
      return NextResponse.json(
        { error: `Upstream returned ${res.status}` },
        { status: res.status }
      );
    }

    const data = await res.json();
    return NextResponse.json(data);
  } catch (e) {
    return NextResponse.json(
      { error: e instanceof Error ? e.message : "Proxy fetch failed" },
      { status: 502 }
    );
  }
}
