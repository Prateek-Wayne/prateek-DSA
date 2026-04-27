class Solution {
    int helper(int m,int n,int[][] dp){
        if(m<0 || n<0 )
            return 0;
        if(m==0 && n==0)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int top=helper(m-1,n,dp);
        int down=helper(m,n-1,dp);
        return dp[m][n]=top+down;
    }
    public int uniquePaths(int m, int n) {
        int[][] dp=new int[m+1][n+1];
        for(int[] temp:dp){
            Arrays.fill(temp,-1);
        }
        return helper(m-1,n-1,dp);
    }
}