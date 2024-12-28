#include <bits/stdc++.h>
using namespace std;

int getLCSLength(string &s1, string &s2)
{
    // your code here
    int ind1 = s1.size();
    int ind2 = s2.size();
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    // bases
    for (int i = 0; i <= ind1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= ind2; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
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
    string ans(dp[ind1][ind2], '$');
    int index = ans.size() - 1;

    for (int temp = 1; temp <= ind2; temp++)
    {
        int i = ind1;
        int j = temp;
        if (dp[ind1][temp] == dp[ind1][ind2])
        {

            while (i > 0 && j > 0)
            {
                if (s1[i] == s2[j])
                {
                    ans[index] = s1[i - 1];
                    index--;
                    i--;
                    j--;
                }
                else if (dp[i][j - 1] > dp[i - 1][j])
                {
                    j--;
                }
                else
                    i--;
            }
            cout << ans << endl;
        }
    }

    // printing the array for now
    return dp[ind1][ind2];
}
int main()
{
    string text1 = "abaaa";
    string text2 = "baabaca";
    // string text1 = "YESBJ";
    // string text2 = "FASEGBZUVC";
    cout << getLCSLength(text1, text2);

    return 0;
}
