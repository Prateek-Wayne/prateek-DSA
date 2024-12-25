#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int ind, vector<int> &ds)
{
    if (ind == 0)
    {
        long long sum = 0;
        for (auto i : nums)
            sum += i;
        long long sum2 = 0;
        for (auto i : ds)
            sum2 += i;
        return abs(sum - 2 * sum2);
    }

    ds.push_back(nums[ind]);
    int pick = helper(nums, ind - 1, ds);
    ds.pop_back();
    int notPick = helper(nums, ind - 1, ds);
    return (min(pick, notPick));
}

int minSubsetSumDifference(vector<int> &nums, int n)
{
    vector<int> ds = {};
    int ind = nums.size();
    return helper(nums, ind - 1, ds);
}
int main()
{
    // vector<int> nums = {3, 9, 7, 3};
    vector<int> nums = {2, -1, 0, 4, -2, -9};
    // vector<int> nums = {-36, +36};
    cout << abs(minSubsetSumDifference(nums, nums.size()));
    return 0;
}