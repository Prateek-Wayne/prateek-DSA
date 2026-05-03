class Solution {
 int helper(int[] nums, int index, int[] dp) {
        int n = nums.length;
        if (index >= n)
            return Integer.MAX_VALUE;
        if (index == n - 1)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int mini = Integer.MAX_VALUE;
        for (int i = 1; i <= nums[index]; i++) {
            int res = helper(nums, index + i, dp);
            if (res != Integer.MAX_VALUE)
                mini = Math.min(mini, 1 + res);
        }
        return dp[index] = mini;

    }

    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        int ans = helper(nums, 0, dp);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}