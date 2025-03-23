//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
int helper(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int>> &dp)
{
    // base
    if (index == 0)
    {
        if (wt[0] <= capacity)
            return val[0] * (capacity / wt[0]);
        return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    int notPick = 0 + helper(val, wt, capacity, index - 1, dp);
    int pick = 0;
    if (wt[index] <= capacity)
    {
        pick = val[index] + helper(val, wt, capacity - wt[index], index, dp);
    }
    return dp[index][capacity] = max(pick, notPick);
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return helper(val, wt, capacity, n - 1, dp);
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