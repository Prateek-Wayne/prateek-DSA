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
        if(n==1)
            return nums[0];
        int[] dp1 = new int[n - 1];
        int[] dp2 = new int[n - 1];
        Arrays.fill(dp1, -1);
        Arrays.fill(dp2, -1);
        int ans1 = helper(Arrays.copyOfRange(nums, 0, n - 1), n - 2, dp1);
        int ans2 = helper(Arrays.copyOfRange(nums, 1, n), n - 2, dp2);
        return Math.max(ans1, ans2);
    }
}