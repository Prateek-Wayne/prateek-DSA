#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;
    if (ind == 0)
    {
        return dp[ind][target] = (nums[0] == target);
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notPick = helper(nums, ind - 1, target, dp);
    bool pick = false;
    if (nums[ind] <= target)
    {
        pick = helper(nums, ind - 1, target - nums[ind], dp);
    }

    return dp[ind][target] = pick || notPick;
}

int minimumDifferenceTabulation(vector<int> &nums)
{
    int n = nums.size() - 1;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += nums[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (nums[i] <= j)
            {
                pick = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = pick || notPick;
        }
    }

    bool ans = dp[n][sum];

    int diff = INT_MAX for (int i = 0; i <= sum; i++)
    {
    }
    cout << "Tabulation\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

int minimumDifference(vector<int> &nums)
{
    int n = nums.size() - 1;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += nums[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    bool ans = false;
    for (int i = 0; i <= sum; i++)
    {
        bool ans = helper(nums, n, i, dp);
    }
    cout << "memo\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][sum];
}
int main()
{
    vector<int> nums = {3, 9, 7, 3};
    cout << minimumDifferenceTabulation(nums);
    cout << minimumDifference(nums);
    return 0;
}