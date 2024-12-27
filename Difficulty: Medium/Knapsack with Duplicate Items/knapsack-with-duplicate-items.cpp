//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

int helper(vector<int> &val, vector<int> &wt, int ind, int W, vector<vector<int>> &dp)
{
    // base
    if (ind == 0)
    {
        if (wt[0] <= W)
            return (W / wt[0]) * val[0];
        return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = helper(val, wt, ind - 1, W, dp);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + helper(val, wt, ind, W - wt[ind], dp);
    return dp[ind][W] = max(pick, notPick);
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = wt.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    return helper(val, wt, n, capacity, dp);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends