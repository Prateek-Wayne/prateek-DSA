import java.util.*;
class Solution {
    // Function to calculate the number of subsets with a given sum
    int helper(int[] nums, int target, int index, Integer[][] dp) {
        if(target<0) return 0;
        if(index<0) return target==0 ? 1 : 0;
        
        if (dp[index][target] != null)
            return dp[index][target];
        int left = helper(nums, target - nums[index], index - 1, dp);
        int right = helper(nums, target, index - 1, dp);
        return left + right;
    }


 public static int perfectSum(int[] nums, int target) {
        int n = nums.length;
        int[][] dp = new int[n][target + 1];

        // Base case: Initialize first row (index 0)
        for (int j = 0; j <= target; j++) {
            if (j == 0 && nums[0] == 0) {
                dp[0][j] = 2; // Two ways: include or exclude the zero
            } else if (j == 0 || j == nums[0]) {
                dp[0][j] = 1; // One way: either target=0 or first element equals target
            } else {
                dp[0][j] = 0; // No way to achieve target j with just nums[0]
            }
        }

        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                // Don't pick current element
                int notPick = dp[i - 1][j];

                // Pick current element (if possible)
                int pick = 0;
                if (j >= nums[i]) {
                    pick = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = pick + notPick;
            }
        }

        return dp[n - 1][target];
    }
}