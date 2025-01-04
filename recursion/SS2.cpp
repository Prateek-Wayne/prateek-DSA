#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> arr, int ind, vector<int> ds, vector<vector<int>> &ans)
{
    if (ind < 0)
    {

        ans.push_back(ds);
        // cout << sum << endl;
        return;
    }
    ds.push_back(arr[ind]);
    helper(arr, ind - 1, ds, ans);
    ds.pop_back();
    helper(arr, ind - 1, ds, ans);
}
vector<vector<int>> subsetSums(vector<int> &arr)
{
    vector<vector<int>> ans;
    helper(arr, arr.size() - 1, {}, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans;
    ans = subsetSums(arr);
    for (const auto &subset : ans)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}