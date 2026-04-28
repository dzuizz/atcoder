import { NextRequest, NextResponse } from "next/server";
import { promises as fs } from "fs";
import path from "path";

const ID_RE = /^[a-z0-9_]+$/;
const INDEX_RE = /^[a-z][a-z0-9]?$/;

export async function POST(request: NextRequest) {
  if (process.env.NODE_ENV === "production") {
    return NextResponse.json({ error: "Disabled in production" }, { status: 403 });
  }

  let body: { contestId?: string; problemIndex?: string };
  try {
    body = await request.json();
  } catch {
    return NextResponse.json({ error: "Invalid JSON body" }, { status: 400 });
  }

  const contestId = (body.contestId ?? "").toLowerCase();
  const problemIndex = (body.problemIndex ?? "").toLowerCase();

  if (!ID_RE.test(contestId) || !INDEX_RE.test(problemIndex)) {
    return NextResponse.json({ error: "Invalid contestId or problemIndex" }, { status: 400 });
  }

  const repoRoot = path.resolve(process.cwd(), "..");
  const templatePath = path.join(repoRoot, "template.cpp");
  const contestDir = path.join(repoRoot, contestId);
  const targetPath = path.join(contestDir, `${problemIndex}.cpp`);

  if (path.relative(repoRoot, targetPath).startsWith("..")) {
    return NextResponse.json({ error: "Path escapes repo root" }, { status: 400 });
  }

  try {
    await fs.access(targetPath);
    return NextResponse.json(
      { error: "File already exists", path: targetPath },
      { status: 409 }
    );
  } catch {
    // not exists, proceed
  }

  try {
    const template = await fs.readFile(templatePath, "utf8");
    await fs.mkdir(contestDir, { recursive: true });
    await fs.writeFile(targetPath, template, { flag: "wx" });
    return NextResponse.json({ ok: true, path: targetPath });
  } catch (e) {
    return NextResponse.json(
      { error: e instanceof Error ? e.message : "Write failed" },
      { status: 500 }
    );
  }
}
