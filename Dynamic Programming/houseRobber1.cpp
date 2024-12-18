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
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        int pick=nums[i];
        if(i>1)
            pick+=dp[i-2];
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[nums.size()-1];
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
    return 0;
}