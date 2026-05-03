class Solution {
 boolean helper(int[] nums, int index, Boolean[] dp) {
        int n = nums.length;
        if (index >= n)
            return false;
        if (index == n - 1)
            return true;
        if (dp[index] != null)
            return dp[index];
        for (int i = 1; i <= nums[index]; i++) {
            if (helper(nums, index + i, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    public boolean canJump(int[] nums) {
        int n = nums.length;
        Boolean[] dp = new Boolean[n];

        return helper(nums, 0, dp);
    }
}