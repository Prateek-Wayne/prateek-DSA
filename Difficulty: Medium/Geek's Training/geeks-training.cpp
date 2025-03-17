//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

int helper(vector<vector<int>> &arr, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == 0)
    {
        int maxy = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i == prev)
                continue;
            maxy = max(maxy, arr[0][i]);
        }
        return dp[curr][prev] = maxy;
    }
    //
    if (dp[curr][prev] != -1)
        return dp[curr][prev];
    int maxy = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i == prev)
            continue;
        maxy = max(maxy, helper(arr, curr - 1, i, dp) + arr[curr][i]);
    }
    return dp[curr][prev] = maxy;
}
int maximumPoints(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>>
        dp(n + 1, vector<int>(m + 1, -1));
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
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends