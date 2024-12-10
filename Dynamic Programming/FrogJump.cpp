#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &height, int n)
{
    if (n == 0)
        return 0;
    if(n==1)
        return height[n-1];
  

    int left = helper(height, n - 1) + abs(height[n] - height[n - 1]);

        int right = helper(height, n - 2) + abs(height[n] - height[n - 2]);

    return min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    return helper(height, n-1);
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = 4;
    cout << minimumEnergy(height, n);
    return 0;
}