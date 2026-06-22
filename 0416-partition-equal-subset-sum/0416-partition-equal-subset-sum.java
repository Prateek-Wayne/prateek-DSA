class Solution {
      public boolean canPartition(int[] nums) {
        int sum = 0;
        int n = nums.length;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        boolean[][] dp = new boolean[n + 1][target + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                boolean pick = false;
                if (nums[i-1] <= j) {
                    pick = dp[i - 1][j - nums[i-1]];
                }
                boolean notPick = dp[i - 1][j];
                dp[i][j] = pick || notPick;
            }
        }
        return dp[n][target];
        // return helper(nums, n - 1, target, dp);
    }
}