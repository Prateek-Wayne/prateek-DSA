//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int helper(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    long long mini = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];

    for (int k = i; k <= j - 1; k++)
    {
       long long steps = arr[i - 1] * arr[k] * arr[j] + helper(arr, i, k,dp) + helper(arr, k + 1, j,dp);
        mini=min(steps, mini);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(arr, 1, n - 1, dp);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends