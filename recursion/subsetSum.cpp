#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, int ind, vector<int> ds)
{
    if (ind == 0)
    {
        ds.push_back(arr[0]);
        int sum = 0;
        for (auto i : ds)
            sum += i;
        cout << sum << endl;
        return;
    }
    // pick..
    ds.push_back(arr[ind]);
    helper(arr, ind - 1, ds);
    ds.pop_back();
    helper(arr, ind - 1, ds);
}


int main()
{
    vector<int> arr = {2, 3};
    helper(arr, arr.size() - 1, {});
    return 0;
}