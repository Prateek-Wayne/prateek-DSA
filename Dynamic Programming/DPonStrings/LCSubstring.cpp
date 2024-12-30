#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string &s1, string &s2)
{
    int ind1 = s1.size();
    int ind2 = s2.size();
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    int ans = 0;

    // base cases
    for (int i = 0; i <= ind1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= ind2; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    // Print the dp array
    for (int i = 0; i <= ind1; i++)
    {
        for (int j = 0; j <= ind2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";
    cout << longestCommonSubstr(s1, s2);

    return 0;
}