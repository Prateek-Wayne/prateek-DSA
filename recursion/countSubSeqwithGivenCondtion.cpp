#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int target, int index, vector<int> &ds)
{
    int mod = 1e9;
    if (index == nums.size())
    {
        int sum = 0;
        if (ds.size())
        {
            if (ds.size() == 1)
            {
                sum += ds[0] * 2;
            }
            else
            {
                sum += ds[0] + ds[ds.size() - 1];
            }
        }
        // ds.size() && ds.size()==1?sum+=ds[0]+ds[0]:ds[0]+ds[ds.size()-1];
        if (sum <= target && ds.size() > 0)
            return 1;
        return 0;
    }
    // add condition...
    ds.push_back(nums[index]);
    int left = helper(nums, target, index + 1, ds);

    // remove cidntion...
    ds.pop_back();
    int right = helper(nums, target, index + 1, ds);
    return (left + right)%mod;
}

int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> ds;
    int sum = 0;
    return helper(nums, target, 0, ds);
}
int main()
{
    vector<int> nums = {3, 5, 6, 7};
    cout << numSubseq(nums, 9);
    return 0;
}