#include <bits/stdc++.h>
using namespace std;

// int helper(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp)
// {
//     if (ind1 == 0 || ind2 == 0)
//         return 0;

//     if (dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];
//     if (text1[ind1 - 1] == text2[ind2 - 1])
//         return dp[ind1][ind2] = 1 + helper(text1, text2, ind1 - 1, ind2 - 1, dp);

//     return dp[ind1][ind2] = max(helper(text1, text2, ind1 - 1, ind2, dp), helper(text1, text2, ind1, ind2 - 1, dp));
// }

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
    // printing the array for now
    return dp[ind1][ind2];
}
int main()
{
    string text1 = "acd";
    string text2 = "ced";
    // string text1 = "YESBJ";
    // string text2 = "FASEGBZUVC";
    cout << getLCSLength(text1, text2);

    return 0;
}