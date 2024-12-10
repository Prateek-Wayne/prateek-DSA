//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

int helper(vector<int> &height,int n,vector<int> &dp) // n is 0 based n-1...
{
    if(n==0)
    {   
        dp[0]=0;
        return 0;
    }
    if(dp[n]!=-1)
        return dp[n];
    int left =helper(height,n-1,dp)+abs( height[n]-height[n-1]);
    int right=INT_MAX;
    if(n>1)
    {
        right=helper(height,n-2,dp)+abs(height[n]-height[n-2]);
    }
    return dp[n]=min(left,right);

}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n+1,-1);
    return helper(height,n-1,dp);
    
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends