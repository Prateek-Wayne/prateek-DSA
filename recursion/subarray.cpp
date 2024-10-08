#include <bits/stdc++.h>
using namespace std;

void recursion(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(ds);
        return;
    }
    // push condition;
    ds.push_back(nums[index]);
    recursion(nums, ans, ds, index + 1);
    ds.pop_back(); // remove condition
    recursion(nums, ans, ds, index+1);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;
    recursion(nums,ans,ds,0);
    return ans;
}

int main()
{
}