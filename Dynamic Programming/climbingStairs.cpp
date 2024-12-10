#include<bits/stdc++.h>
using namespace std;

int helper(int n,vector<int> & dp)
{
    if(n==0||n==1)
        return dp[n]=1;
    if(dp[n]!=-1)
        return dp[n];
    else
        return dp[n]=helper(n-1,dp)+helper(n-2,dp);

}
 int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }

int main()
{
 return 0;
}