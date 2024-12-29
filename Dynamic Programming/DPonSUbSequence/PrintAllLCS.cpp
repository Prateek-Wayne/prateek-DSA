#include <bits/stdc++.h>
using namespace std;
vector<string> all_longest_common_subsequences(string s, string t)
{
    int ind1 = s.size();
    int ind2 = t.size();
    set<string> result;
    vector<string> finalString;
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
    cout << "DP Table:" << endl;
    for (int i = 0; i <= ind1; i++) {
        for (int j = 0; j <= ind2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int len = dp[ind1][ind2];
    for (int tempi = 1; tempi <= ind1; tempi++)
    {
        for (int temp = 1; temp <= ind2; temp++)
        {
            if (dp[tempi][temp] == len)
            {
                int i = tempi;
                int j = temp;
                string ans(len, '$');
                int index = len - 1;
                while (i > 0 && j > 0)
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        ans[index] = s[i - 1];
                        i--;
                        j--;
                        index--;
                    }
                    else if (dp[i][j - 1] > dp[i - 1][j])
                    {
                        j--;
                    }
                    else
                        i--;
                }

                result.insert(ans);
                cout << ans << "|";
            }
        }
    }
    for (auto i : result)
    {
        // cout << i << endl;

        finalString.push_back(i);
    }

    return finalString;
}

int main()
{
    string text1 = "abaaa";
    string text2 = "baabaca";

    vector<string> lcs = all_longest_common_subsequences(text1, text2);
    for (const string &str : lcs)
    {
        cout << str << endl;
    }

    return 0;
}