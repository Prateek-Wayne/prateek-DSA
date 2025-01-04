#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &height, int ind)
{
    if (ind == 0)
        return 0;
    int left = helper(height, ind - 1) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = helper(height, ind - 2) + abs(height[ind] - height[ind - 2]);
    return min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    return helper(height, n - 1);
}
int main()
{
    vector<int> arr = {10, 20, 30, 10};
    int n = arr.size();
    cout << minimumEnergy(arr, n);
    return 0;
}