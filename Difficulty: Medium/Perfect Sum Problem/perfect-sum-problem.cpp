//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:


int helper(vector<int> &arr, int index, int &target, vector<vector<int>> &dp)
{
    if (target < 0)
        return 0;
    // if (target == 0)
    //     return 1;
    if (index == 0)
    {
        if (target == 0 && arr[index] == 0)
            return 2;
        if (target == 0 || arr[index] == target)
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    target -= arr[index];
    int left = helper(arr, index - 1, target, dp);
    target += arr[index];
    int right = helper(arr, index - 1, target, dp);
    return dp[index][target] = left + right;
}
int perfectSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return helper(arr, n - 1, target, dp);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends