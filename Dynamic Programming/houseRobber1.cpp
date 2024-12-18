#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int index, vector<int> &dp)
{
    if (index == 0)
    {
        return nums[0];
    }
    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = helper(nums, index - 2, dp) + nums[index];
    int notPick = helper(nums, index - 1, dp) + 0;

    return dp[index] = max(pick, notPick);
}
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return helper(nums, nums.size() - 1, dp);
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
    return 0;
}