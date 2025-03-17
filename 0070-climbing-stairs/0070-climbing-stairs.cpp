class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (n == 0)
            return dp[n] = 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int left = helper(n - 1, dp);
        int right = helper(n - 2, dp);
        return dp[n] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};