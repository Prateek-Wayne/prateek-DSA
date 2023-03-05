class Solution {
public:
   int calc(int n,vector<int> &dp)
    {
        if(n<0)
            return 0;
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int left = calc(n-1,dp);
        int right = calc(n-2,dp);
        return dp[n] = left + right;
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return calc(n,dp);
    }
};