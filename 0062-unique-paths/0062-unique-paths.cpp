class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp) {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int left = 0;
        if (m - 1 >= 0) {
            left = helper(m - 1, n, dp);
        }
        int right = 0;
        if (n - 1 >= 0) {
            right = helper(m, n - 1, dp);
        }
        return dp[m][n] = left + right;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(m - 1, n - 1, dp);
    }
};