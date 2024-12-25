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
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return helper(arr, n, target, dp);
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