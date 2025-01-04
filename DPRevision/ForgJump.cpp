#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &height, int ind, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = helper(height, ind - 1, dp) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = helper(height, ind - 2, dp) + abs(height[ind] - height[ind - 2]);
    return dp[ind] = min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n, -1);
    return helper(height, n - 1, dp);
}
int main()
{
    vector<int> arr = {10, 20, 30, 10};
    int n = arr.size();
    cout << minimumEnergy(arr, n);
    return 0;
}