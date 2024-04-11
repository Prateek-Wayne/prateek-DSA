class Solution {
public:
    int climbStairsRec(int n,vector<int> &dp) {
        // base condition....
        if(n==0||n==1)
        {
            return dp[n]=1;
        }
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=climbStairsRec(n-1,dp)+climbStairsRec(n-2,dp);
        
    }

    int climbStairs(int n) {
        // base condition....
        vector<int> dp(n+1,-1);
        return climbStairsRec(n,dp);
        
    }
};