#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &arr, int d)
{

    int n = arr.size() - 1;
    int target = 0;
    for (int i = 0; i <= n; i++)
    {
        target += arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
            {
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = pick + notPick;
        }
    }
    int count = 0;
    for (int i = 0; i <= target; i++)
    {
        if (dp[n][i])
        {

             if (i == (target - d) / 2)
            {
                count++;
            }
        }
    }
    // cout << "Tabulation\n";
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= target; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return count;
}
int main()
{
    vector<int> arr = {1, 1, 1, 1};
    int d = 0;

    cout << endl
         << countPartitions(arr, d);
    return 0;
}