class Solution {
public:
    int helper(vector<vector<int>>& triangle, int R, int C,
               vector<vector<int>>& dp) {
        int n = triangle.size();
        if (R == n - 1)
            return triangle[R][C];
        if (R >= n)
            return 0;
        if (dp[R][C] != -1)
            return dp[R][C];
        int left = helper(triangle, R + 1, C, dp) + triangle[R][C];
        int right = helper(triangle, R + 1, C + 1, dp) + triangle[R][C];
        return dp[R][C] = min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(triangle[n - 1].size() + 1, -1));
        return helper(triangle, 0, 0, dp);
    }
};