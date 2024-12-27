//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.

int helper(vector<int> &val, vector<int> &wt, int ind, int W, vector<vector<int>> &dp)
{
    // base
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = helper(val, wt, ind - 1, W, dp) + 0;
    int pick = INT_MIN;
    if (wt[ind] <= W)
    {
        pick = val[ind] + helper(val, wt, ind - 1, W - wt[ind], dp);
    }
    return dp[ind][W] = max(pick, notPick);
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // code here
    int n = val.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    return helper(val, wt, n, capacity, dp);
}
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends