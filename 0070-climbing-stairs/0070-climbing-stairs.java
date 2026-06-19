class Solution {

    public int helper(int n,int[] dp){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int twoSteps=helper(n-2,dp);
        int oneSteps=helper(n-1,dp);
        return dp[n]= twoSteps+oneSteps;
    }
    public int climbStairs(int n) {
        int[] dp=new int[n+1];
        Arrays.fill(dp,-1);
        return helper(n,dp);
    }
}