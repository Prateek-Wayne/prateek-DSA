#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int target, int ind, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return target == arr[0];

    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notpick = helper(arr, target, ind - 1, dp);

    bool pick = false;
    if (arr[ind] <= target)
        pick = helper(arr, target - arr[ind], ind - 1, dp);

    return dp[ind][target] = pick || notpick;
}

bool isSubsetSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    return helper(arr, target, n, dp);
}

bool isSubsetSumTabulation(vector<int> &arr, int target)
{
    // code here
    int n = arr.size() - 1;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notpick = dp[i - 1][j];

            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = pick || notpick;
        }
    }
    return dp[n][target];
}
int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 1;
    cout << isSubsetSumTabulation(arr, target);
    return 0;
}