class Solution {
    int helper(String s1,String s2,int i,int j,Integer[][] dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=null)
            return dp[i][j];
        // Pick;
        int pick=0;
        if(s1.charAt(i)==s2.charAt(j)){
            pick=1+helper(s1,s2,i-1,j-1,dp);
        }
        int notPick=0+Math.max(helper(s1,s2,i-1,j,dp),helper(s1,s2,i,j-1,dp));
        return dp[i][j]= Math.max(pick,notPick);
    }



    public int longestPalindromeSubseq(String s) {
        int n=s.length();
        int m=s.length();
        Integer[][] dp=new Integer[n+1][m+1];
        String s2 = new StringBuilder(s).reverse().toString();
        return helper(s,s2,n-1,m-1,dp);
        
    }
}