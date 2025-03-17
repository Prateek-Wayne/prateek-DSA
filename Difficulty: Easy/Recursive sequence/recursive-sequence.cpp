//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
 

public:

int MOD = 1e9 + 7;

int helper(int n, vector<int> &dp)
{

    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    long long first = 1+ ((n * (n - 1)) / 2);
    long long temp = 1;
    for (long long i = 0; i < n; i++)
        temp = (temp * (first + i)) % MOD;
    return dp[n] = (temp + helper(n - 1, dp)) % MOD;
}

long long sequence(int n)
{
    vector<int> dp(n + 1, -1);
    long long ans = helper(n, dp);
    return ans % MOD;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends