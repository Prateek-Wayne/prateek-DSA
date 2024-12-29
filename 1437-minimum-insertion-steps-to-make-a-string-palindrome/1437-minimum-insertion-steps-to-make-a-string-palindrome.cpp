class Solution {
public:
int minInsertions(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int ind1 = s.length();
    int ind2 = ind1;
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    for (int i = 0; i <= ind1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= ind2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
            if (s[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs = dp[ind1][ind2];
    return ind1 - lcs;
}
};