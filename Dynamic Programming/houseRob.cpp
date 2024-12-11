#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &height,int n,vector<int> &dp)
{
    if(n==0)
    {
        dp[0]=height[0];
        return height[0];
    }
    if(n<0)
        return 0;

    if(dp[n]!=-1)
        return dp[n];
    int left=INT_MIN;

    if(n>=2)
    {
        left=helper(height,n-2,dp)+height[n];
    }
    int right=helper(height,n-1,dp)+0;
    dp[n]=max(left,right);
    return dp[n] ;
}

int rob(vector<int> &nums)
{   
    vector<int> dp(nums.size()+1,-1);
    return helper(nums,nums.size(),dp);
    
}

int main()
{
    vector<int> house={1,2,3,1};
    cout<<rob(house);
    
    return 0;
}