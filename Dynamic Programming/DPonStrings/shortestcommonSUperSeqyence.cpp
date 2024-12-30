#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2)
{
    int ind1 = s1.length();
    int ind2 = s2.length();
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    for (int i = 0; i <= ind1; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= ind2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    int i = ind1;
    int j = ind2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            ans += s2[j - 1];
            j--;
        }
        else
        {
            ans += s1[i - 1];
            i--;
        }
    }
    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string str1 = "abac";
    string str2 = "cab";
    cout << shortestCommonSupersequence(str1, str2);
    return 0;
}