//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
int helper(vector<vector<int>> &arr, int ind, int prev, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        int ans = INT_MIN;
        for (int i = 0; i <= 2; i++)
        {
            if (i != prev)
                ans = max(ans, arr[0][i]);
        }
        return ans;
    }
    if (dp[ind][prev] != -1)
        return dp[ind][prev];
    int ans = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != prev)
        {
            ans = max(ans, helper(arr, ind - 1, i, dp) + arr[ind][i]);
        }
    }
    return dp[ind][prev] = ans;
}

int maximumPoints(vector<vector<int>> &arr, int n)
{

    vector<vector<int>> dp(n, vector<int>(arr[0].size() + 1, -1));
    return helper(arr, n - 1, 3, dp);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends