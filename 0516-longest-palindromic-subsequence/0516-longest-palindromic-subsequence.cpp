class Solution {
public:
    int helper(string& s1, string& s2, int ind1, int ind2,
               vector<vector<int>>& dp) {
        if (ind1 == 0 || ind2 == 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1 - 1] == s2[ind2 - 1])
            return dp[ind1][ind2] = 1 + helper(s1, s2, ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = max(helper(s1, s2, ind1 - 1, ind2, dp),
                                    helper(s1, s2, ind1, ind2 - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        int ind1 = s.length();
        int ind2 = ind1;
        string s2 = s;
        vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
        reverse(s2.begin(), s2.end());
        return helper(s, s2, ind1, ind2, dp);
    }
};