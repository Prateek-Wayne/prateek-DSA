#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (arr[ind] == target)
            return 1;
        else
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
    int n = arr.size() - 1;
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
    return dp[n][target];
}
int main()
{
    // vector<int> arr = {2, 5, 1, 4, 3};
    vector<int> arr = {2, 5, 1, 4, 3};
    //     28 4 3 27 0 24 26
    // 24
    cout << perfectSum(arr, 10);
    return 0;
}