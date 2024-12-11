#include <bits/stdc++.h>
using namespace std;

int helper(int n, int k, vector<int> &height)
{
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int jump = INT_MAX;
        if (n >= i)
        {
            int jump = helper(n - i, k, height) + abs(height[n] - height[n - i]);
            ans = min(ans, jump);
        }
    }
    return ans;
}

int minimizeCost(int k, vector<int> &arr)
{
    return helper(arr.size() - 1, k, arr);
}
int main()
{
    vector<int> arr = {96, 48, 27, 72, 39, 70, 13, 68, 100};
    int k = 7;
    // vector<int> arr = {10, 30, 40, 50, 20};
    // vector<int> arr = {10,20,10};
    // int k = 1;
    cout << minimizeCost(k, arr) << endl;
    return 0;
}