//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

int helper(vector<vector<int>> &arr, int d, int last, vector<vector<int>> &dp)
{
    // base..
    if (d == 0)
    {
        int temp = INT_MIN;
        for (int i = 0; i < arr[0].size(); i++)
        {
            if (i != last)
            {
                temp = max(temp, arr[d][i]);
            }
        }
        dp[d][last] = temp;
        return temp;
    }
    if (dp[d][last] != -1 && last < arr[0].size())
        return dp[d][last];
    int ans = INT_MIN;
    for (int i = 0; i < arr[0].size(); i++)
    {

        if (i != last)
        {
            int temp = helper(arr, d - 1, i, dp) + arr[d][i];
            ans = max(ans, temp);
        }
    }
    dp[d][last] = ans;
    return ans;
}

int maximumPoints(vector<vector<int>> &arr, int n)
{
    // Code here
    int days = arr.size() - 1;
    int last = arr[0].size();
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), -1));
    return helper(arr, days, last, dp);
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