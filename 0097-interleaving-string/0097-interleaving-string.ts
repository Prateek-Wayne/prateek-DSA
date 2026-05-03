const helper = (
  s1: string,
  s2: string,
  s3: string,
  i: number,
  j: number,
  memo: Map<string, boolean>
): boolean => {
  const key = `${i}|${j}`;

  if (memo.has(key)) return memo.get(key)!;

  const k = i + j;

  if (k === s3.length) return true;

  let result = false;

  if (i < s1.length && s1[i] === s3[k]) {
    result = helper(s1, s2, s3, i + 1, j, memo);
  }

  if (!result && j < s2.length && s2[j] === s3[k]) {
    result = helper(s1, s2, s3, i, j + 1, memo);
  }

  memo.set(key, result);
  return result;
};

function isInterleave(s1: string, s2: string, s3: string): boolean {
  if (s1.length + s2.length !== s3.length) return false;

  return helper(s1, s2, s3, 0, 0, new Map());
}