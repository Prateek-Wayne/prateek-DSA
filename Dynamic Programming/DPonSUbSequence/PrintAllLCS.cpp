#include <bits/stdc++.h>
using namespace std;
vector<string> all_longest_common_subsequences(string s, string t)
{
    int ind1 = s.size();
    int ind2 = t.size();
    vector<string> result;
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, 0));
    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {

            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[ind1][ind2];
    for (int temp = 1; temp <= ind2; temp++)
    {
        if (dp[ind1][temp] == len)
        {
            int i = ind1;
            int j = temp;
            string ans(len, '$');
            int index = len - 1;
            while (i > 0 && j > 0)
            {
                if (s[i - 1] == t[j - 1])
                {
                    ans[len] = s[i - 1];
                }
                else if (dp[i][j - 1] > dp[i - 1][j])
                {
                    j--;
                }
                else
                    i--;
            }
            result.push_back(ans);
        }
    }

    return result;
}
int main()
{

    return 0;
}