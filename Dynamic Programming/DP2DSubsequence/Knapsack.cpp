#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &val, vector<int> &wt, int ind, int W)
{
    // base
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    int notPick = helper(val, wt, ind - 1, W) + 0;
    int pick = INT_MIN;
    if (wt[ind] <= W)
    {
        pick = val[ind] + helper(val, wt, ind - 1, W - wt[ind]);
    }
    return max(pick, notPick);
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // code here
    int n = val.size() - 1;
    return helper(val, wt, n, capacity);
}
int main()
{
    //  capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
    int capacity = 5;
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 6, 3};

    cout << knapSack(capacity, val, wt) << endl;
    return 0;
}