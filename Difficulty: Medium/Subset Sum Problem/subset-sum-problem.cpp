//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

bool helper(vector<int> &arr, int target, int ind, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return target == arr[0];

    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notpick = helper(arr, target, ind - 1, dp);

    bool pick = false;
    if (arr[ind] <= target)
        pick = helper(arr, target - arr[ind], ind - 1, dp);

    return dp[ind][target] = pick || notpick;
}

bool isSubsetSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    return helper(arr, target, n, dp);
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