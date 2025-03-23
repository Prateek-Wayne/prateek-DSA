//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:

int helper(vector<int> &price, int index, int N, vector<vector<int>> &dp)
{
    // base
    if (index == 0)
    {
        int rodLength = index + 1;
        if (rodLength <= N)
            return price[index] * (N / rodLength);
        return 0;
    }
    if (dp[index][N] != -1)
        return dp[index][N];
    int notPick = 0 + helper(price, index - 1, N, dp);
    int pick = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= N)
    {
        pick = price[index] + helper(price, index, N - rodLength, dp);
    }
    return dp[index][N] = max(pick, notPick);
}
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return helper(price, n - 1, n, dp);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends