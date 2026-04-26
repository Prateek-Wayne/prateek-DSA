class Solution {
int helper(int[] nums, int index, int prev, int[][] dp) {
    int n = nums.length;
    if (index == n) return 0;
    if (dp[index][prev + 1] != -1) return dp[index][prev + 1];
    
    int left = 0;
    if (prev == -1 || nums[prev] < nums[index]) {
        left = 1 + helper(nums, index + 1, index, dp);
    }
    int right = helper(nums, index + 1, prev, dp);  // skip: prev unchanged
    return dp[index][prev + 1] = Math.max(left, right);
}

public int lengthOfLIS(int[] nums) {
    int n = nums.length;
    int[][] dp = new int[n][n + 1];  // prev+1 ranges 0..n
    for (int[] temp : dp) Arrays.fill(temp, -1);
    return helper(nums, 0, -1, dp);
}
}