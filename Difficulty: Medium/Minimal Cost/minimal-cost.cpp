//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 int helper(vector<int> &arr, int ind, int k, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    int ans = INT_MAX;
    if (dp[ind] != -1)
        return dp[ind];
    for (int i = 1; i <= k; i++)
    {

        if (ind > (i - 1))
        {
            int jump = helper(arr, ind - i, k, dp) + abs(arr[ind] - arr[ind - i]);
            ans = min(ans, jump);
        }
    }
    return dp[ind] = ans;
}
int minimizeCost(int k, vector<int> &arr)
{
    // vector<int> ans;
    int n = arr.size() - 1;
    vector<int> dp(n + 1, -1);
    return helper(arr, n, k, dp);
}
};

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