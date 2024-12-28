class Solution {
public:
    int helper(string text1, string text2, int ind1, int ind2,
               vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (text1[ind1] == text2[ind2])
            return dp[ind1][ind2] =
                       1 + helper(text1, text2, ind1 - 1, ind2 - 1, dp);

        return dp[ind1][ind2] = max(helper(text1, text2, ind1 - 1, ind2, dp),
                                    helper(text1, text2, ind1, ind2 - 1, dp));
    }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int ind1 = text1.size() - 1;
    //     int ind2 = text2.size() - 1;
    //     vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 2, -1));
    //     return helper(text1, text2, ind1, ind2, dp);
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
        for (int i = 0; i <= ind1; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= ind2; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= ind1; i++) {
            for (int j = 1; j <= ind2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[ind1][ind2];
    }
};