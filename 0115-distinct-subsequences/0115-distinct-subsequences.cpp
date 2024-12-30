class Solution {
public:
    int helper(string& s, string& t, int ind1, int ind2,
               vector<vector<int>>& dp) {
        if (ind2 < 0)
            return 1;
        if (ind1 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == t[ind2]) {
            return dp[ind1][ind2] = helper(s, t, ind1 - 1, ind2 - 1, dp) +
                                    helper(s, t, ind1 - 1, ind2, dp);
        }
        return dp[ind1][ind2] = helper(s, t, ind1 - 1, ind2, dp);
    }

    int numDistinct(string s, string t) {
        int ind1 = s.length() - 1;
        int ind2 = t.length() - 1;
        vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));

        return helper(s, t, ind1, ind2, dp);
    }
};