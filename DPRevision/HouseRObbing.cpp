#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr, int ind, vector<int> &dp)
{
    if (ind == 0)
        return arr[ind];
    if (dp[ind] != -1)
        return dp[ind];
    int notRob = helper(arr, ind - 1, dp) + 0;
    int rob = INT_MIN;
    if (ind > 1)
        rob = helper(arr, ind - 2, dp) + arr[ind];
    return dp[ind] = max(rob, notRob);
}

int rob(vector<int> &nums)
{
    int n = nums.size() - 1;
    vector<int> dp(n + 1, -1);
    return helper(nums, n, dp);
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
    return 0;
}