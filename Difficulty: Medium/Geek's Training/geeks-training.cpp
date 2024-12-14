//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:


int helper(vector<vector<int>> &arr, int last, int days, vector<vector<int>> &dp)
{ // base...
    if (days == 0)
    {
        int temp = INT_MIN;
        for (int i = 0; i < arr[0].size(); i++)
        {

            if (i != last)
            {
                temp = max(temp, arr[days][i]);
                dp[0][i] = temp;
            }
        }
        return temp;
    }
   if (dp[days][last] != -1&& last< arr[0].size())
        return dp[days][last];
    int ans = INT_MIN;
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (i != last)
        {
            int temp = helper(arr, i, days - 1, dp) + arr[days][i];
            ans = max(ans, temp);
        }
    }
    dp[days][last] = ans;
    return ans;
}

int maximumPoints(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(arr[0].size(), -1));
    return helper(arr, arr[0].size(), n - 1, dp);
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