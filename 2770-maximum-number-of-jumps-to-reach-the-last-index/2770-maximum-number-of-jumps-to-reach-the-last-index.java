class Solution {
    int helper(int[] jumps, int target, int index, int[] dp) {
        int n = jumps.length;
        if (index == n - 1)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int steps = Integer.MIN_VALUE;
        for (int i = index + 1; i < n; i++) {
            int diff = Math.abs(jumps[index] - jumps[i]);
            if (diff <= target) {
                int result = helper(jumps, target, i, dp);
                if (result != Integer.MIN_VALUE) {
                    steps = Math.max(steps, 1 + result);
                }
            }
        }
        return dp[index] = steps;

    }

    public int maximumJumps(int[] nums, int target) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        int ans = helper(nums, target, 0, dp);

        return ans == Integer.MIN_VALUE ? -1 : ans;
    }
}