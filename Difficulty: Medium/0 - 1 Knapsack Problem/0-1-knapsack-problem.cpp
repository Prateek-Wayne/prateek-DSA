//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int helper(int W, vector<int> &val, vector<int> &wt, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[index] <= W)
            return val[index];
        return 0;
    }
    if (dp[index][W] != -1)
        return dp[index][W];
    // not pick...
    int notPick = 0 + helper(W, val, wt, index - 1, dp);
    int pick = INT_MIN;
    if (wt[index] <= W)
    {
        pick = val[index] + helper(W - wt[index], val, wt, index - 1, dp);
    }
    return dp[index][W] = max(pick, notPick);
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return helper(W, val, wt, n - 1, dp);
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
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends