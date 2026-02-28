class Solution {
    int helper(int[] nums, int index, int[] dp) {
        if (index < 0) {
            return 0;
        }
        if (dp[index] != -1)
            return dp[index];
        int left = nums[index] + helper(nums, index - 2, dp);
        int right = 0 + helper(nums, index - 1, dp);
        return dp[index] = Math.max(left, right);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return helper(nums, n - 1, dp);
    }
}