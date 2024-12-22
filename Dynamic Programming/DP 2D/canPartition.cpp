#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &nums, int target, int ind, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return target == nums[ind];

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notPick = helper(nums, target, ind - 1, dp);
    bool pick = false;
    if (nums[ind] <= target)
        pick = helper(nums, target - nums[ind], ind - 1, dp);
    return dp[ind][target] = pick || notPick;
}

bool canPartition(vector<int> &nums)
{
    int target = 0;
    for (int i = 0; i < nums.size(); i++)
        target += nums[i];
    if (target % 2 != 0)
        return false;

    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return helper(nums, target / 2, nums.size() - 1, dp);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
    return 0;
}