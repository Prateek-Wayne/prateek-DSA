function rotateString(s: string, goal: string): boolean {
  if (s.length != goal.length) return false;
  const ss: string = s + s;
  return ss.includes(goal);
}
