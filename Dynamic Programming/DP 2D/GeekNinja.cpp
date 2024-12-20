#include <bits/stdc++.h>
using namespace std;

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
int main()
{
    // Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    // 2,1,6| 3,4,6  | 10,1,6 | 8,3,7
    // vector<vector<int>> arr = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int n = 3;
    cout << maximumPoints(arr, n) << endl;
    return 0;
}