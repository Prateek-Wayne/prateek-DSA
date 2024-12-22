#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int target, int ind)
{
    if (ind == 0)
        return target == 0;

    if (ind < 0 || target < 0)
        return false;
    int pick = helper(arr, target - arr[ind], ind - 1);
    int notpick = helper(arr, target, ind - 1);

    return pick || notpick;
}

bool isSubsetSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size() - 1;
    vector<int> dp(n + 1, -1);

    return helper(arr, target, n);
}
int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 30;
    cout << isSubsetSum(arr, target);
    return 0;
}