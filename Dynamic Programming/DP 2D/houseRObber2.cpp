#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums, int index,vector<int> &dp)
{
    if (index == 0)
    {
        return nums[index];
    }
    if (index < 0)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    int pick = helper(nums, index - 2,dp) + nums[index];
    int notPick = helper(nums, index - 1,dp) + 0;
    return dp[index]=max(pick, notPick);
}

int rob(vector<int> &nums)
{   int n=nums.size()-1;
    vector<int> dp1(n+1,-1);
    vector<int> dp2(n+1,-1);
    vector<int> first;
    vector<int> second;
    first.assign(nums.begin(),nums.end()-1);
    second.assign(nums.begin()+1,nums.end());
    return max(helper(first,n-1,dp1),helper(second,n-1,dp2));
}
int main()
{   
    vector<int> nums={1};
    cout<<rob(nums);
    return 0;
}