class Solution {
public:
    int helper(string& s, string& t, int ind1, int ind2,
               vector<vector<int>>& dp) {
        if (ind2 == 0)
            return 1;
        if (ind1 == 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1 - 1] == t[ind2 - 1]) {
            return dp[ind1][ind2] = helper(s, t, ind1 - 1, ind2 - 1, dp) +
                                    helper(s, t, ind1 - 1, ind2, dp);
        }
        return dp[ind1][ind2] = helper(s, t, ind1 - 1, ind2, dp);
    }

    // int numDistinct(string s, string t) {
    //     int ind1 = s.length();
    //     int ind2 = t.length();
    //     vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));

    //     return helper(s, t, ind1, ind2, dp);
    // }
    
int numDistinct(string s, string t)
{
    int ind1 = s.length();
    int ind2 = t.length();
    vector<vector<double>> dp(ind1 + 1, vector<double>(ind2 + 1, 0));
    // bases...
    for (int i = 0; i <= ind1; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= ind2; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return int(dp[ind1][ind2]);
}
};