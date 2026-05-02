function rotatedDigits(n: number): number {
  let count: number = 0;
  for (let i = 1; i <= n; i++) {
    let mirrored: boolean = false;
    let valid: boolean = true;
    let num = i;
    while (num != 0) {
      const first = num % 10;
      num = Math.floor(num / 10);
      if (first == 2 || first == 5 || first == 6 || first == 9) mirrored = true;
      if (first == 3 || first == 4 || first == 7) valid = false;
    }
    if (valid && mirrored) count++;
  }
  return count;
}
