class Solution {
    public int zigZagArrays(int n, int l, int r) {
        int MOD = 1_000_000_007;
        r -= l;
        int[] dp = new int[r + 1];
        Arrays.fill(dp, 1);
        for (int i = 1; i < n; i++) {
            int pre = 0, pre2;
            if ((i & 1) == 1) {
                for (int v = 0; v <= r; v++) {
                    pre2 = pre + dp[v];
                    dp[v] = pre;
                    pre = pre2 % MOD;
                }
            } else {
                for (int v = r; v >= 0; v--) {
                    pre2 = pre + dp[v];
                    dp[v] = pre;
                    pre = pre2 % MOD;
                }
            }
        }
        int res = 0;
        for (int v : dp)
            res = (res + v) % MOD;
        return res * 2 % MOD;
    }
}