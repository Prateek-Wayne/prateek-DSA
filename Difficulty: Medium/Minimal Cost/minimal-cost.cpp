//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:


int helper(int n, int k, vector<int> &height, vector<int> &dp)
{
    if (n == 0)
    {
        dp[0] = 0;
        return 0;
    }

    if(dp[n]!=-1)
        return dp[n];
    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        int jump = INT_MAX;
        if (n >= i)
        {
            int jump = helper(n - i, k, height,dp) + abs(height[n] - height[n - i]);
            ans = min(ans, jump);
        }
    }
    dp[n]=ans;
    return dp[n];
}

int minimizeCost(int k, vector<int> &arr)
{   
    vector<int> dp(arr.size(),-1);
    return helper(arr.size() - 1, k, arr,dp);
}};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends