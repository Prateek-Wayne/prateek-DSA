class Solution {
public:
    int LCS(string A,string B,int n,int m)
  {
      int dp[n+1][m+1];
      memset(dp,0,sizeof(dp));
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          {
            if(A[i-1]==B[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }              
              
          }
      }
      return dp[n][m];
  }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int ans=LCS(s,t,n,m);
        if(n==ans)
            return true;
        return false;
        
    }
};