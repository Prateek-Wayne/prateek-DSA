#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    int ind1 = word1.size();
    int ind2 = word2.size();
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    for (int i = 0; i <= ind1; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= ind2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs = dp[ind1][ind2];
    return (word1.length() + word2.length()) - 2 * lcs;
}
int main()
{
    return 0;
}