class Solution {
  boolean helper(int[] nums, int index, int target, Boolean[][] dp) {
        if (target == 0) {
            return true;
        }
        if (index == 0) {
            if (target == nums[index])
                return true;
            return false;
        }
        if (dp[index][target] != null)
            return dp[index][target];

        boolean pick = false;
        if (nums[index] <= target)
            pick=helper(nums, index - 1, target - nums[index], dp);
        boolean notPick = helper(nums, index - 1, target, dp);
        return dp[index][target] = pick || notPick;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        int n = nums.length;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        Boolean[][] dp = new Boolean[n + 1][target + 1];
        return helper(nums, n - 1, target, dp);
    }
}