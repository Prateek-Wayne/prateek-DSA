#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &arr, int ind, int k, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    int ans = INT_MAX;
    if (dp[ind] != -1)
        return dp[ind];
    for (int i = 1; i <= k; i++)
    {

        if (ind > (i - 1))
        {
            int jump = helper(arr, ind - i, k, dp) + abs(arr[ind] - arr[ind - i]);
            ans = min(ans, jump);
        }
    }
    return dp[ind] = ans;
}
int minimizeCost(int k, vector<int> &arr)
{
    // vector<int> ans;
    int n = arr.size() - 1;
    vector<int> dp(n + 1, 0);
    for (int ind = 1; ind <= n; ind++)
    {
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (ind > (i - 1))
            {
                int jump = abs(arr[ind] - arr[ind - i]) + dp[ind - i];
                ans = min(jump, ans);
            }
        }
        dp[ind] = ans;
    }
    return dp[n];
}
// int minimizeCost(int k, vector<int> &arr)
// {
//     // vector<int> ans;
//     int n = arr.size() - 1;
//     vector<int> dp(n + 1, -1);
//     return helper(arr, n, k, dp);
// }
int main()
{
    vector<int> arr = {10, 30, 40, 50, 20};
    cout << minimizeCost(3, arr);
    return 0;
}