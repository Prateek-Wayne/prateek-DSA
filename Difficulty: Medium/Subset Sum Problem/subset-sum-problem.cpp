//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
 int helper(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notPick = helper(arr, ind - 1, target, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = helper(arr, ind - 1, target - arr[ind], dp);
    }
    return dp[ind][target] = pick || notPick;
}
bool isSubsetSum(vector<int> &arr, int target)
{
    int n = arr.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return helper(arr, n, target, dp);
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends