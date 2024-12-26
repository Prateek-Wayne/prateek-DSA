#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0)
            return 1;
        if (target == arr[ind])
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notPick = helper(arr, ind - 1, target, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = helper(arr, ind - 1, target - arr[ind], dp);
    }
    return dp[ind][target] = pick + notPick;
}
int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return helper(arr, n - 1, target, dp);
}

int perfectSumTabulation(vector<int> &arr, int target)
{
    int n = arr.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= target; i++)
    {
        if (i == 0 && arr[0] == 0)
        {
            dp[0][i] = 2;
            continue;
        }
        else if (i == 0)
        {
            dp[0][i] = 1;
        }
        else if (i == arr[0])
        {
            dp[0][i] = 1;
        }
        else
            dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
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
    return dp[n][target];
}
int main()
{
    vector<int> arr = {28, 4, 3, 27, 0, 24, 26};
    int d = 24;
    cout << perfectSumTabulation(arr, d);
    return 0;
}