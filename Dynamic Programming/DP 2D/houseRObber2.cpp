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
    vector<int> first(nums.begin(),nums.end()-1);
    if(n==0)
        return nums[0];
    vector<int> second(nums.begin()+1,nums.end());

     vector<int> dp1(first.size(),-1);
    vector<int> dp2(second.size(),-1);
    
    dp1[0]=first[0];

    dp2[0]=second[0];
    for(int i=1;i<first.size();i++)
    {
        int pick=first[i];
        if(i>1)
            pick+=dp1[i-2];
        int notpick=dp1[i-1]+0;

        dp1[i]=max(pick,notpick);
        
    }

     for(int i=1;i<second.size();i++)
    {
        int pick=second[i];
        if(i>1)
            pick+=dp2[i-2];
        int notpick=dp2[i-1]+0;

        dp2[i]=max(pick,notpick);  
    }
    return max(dp1[dp1.size()-1],dp2[dp2.size()-1]);
   
}
int main()
{   
    // vector<int> nums={2,3,2};
    vector<int> nums={2};
    cout<<rob(nums);
    return 0;
}