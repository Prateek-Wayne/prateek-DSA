#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> arr, int ind, vector<int> ds, vector<int> &ans)
{
    if (ind < 0)
    {
        int sum = 0;
        for (auto i : ds)
            sum += i;
        ans.push_back(sum);
        // cout << sum << endl;
        return;
    }
    ds.push_back(arr[ind]);
    helper(arr, ind - 1, ds, ans);
    ds.pop_back();
    helper(arr, ind - 1, ds, ans);
}
vector<int> subsetSums(vector<int> &arr)
{
    vector<int> ans;
    helper(arr, arr.size() - 1, {}, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1,2,2};
    vector<int> ans;
    ans = subsetSums(arr);

    return 0;
}