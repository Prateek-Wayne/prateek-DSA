#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &arr)
{
    int l = 0;
    int r = 0;
    int sum = 0;
    int ans = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum < target)
        {
            sum += arr[r];
            r++;
        }
        if (sum >= target)
        {
            while (sum >= target)
            {
                ans = min(ans, r - l);
                cout<<"Ans value at"<<l<<","<<r<<":"<<ans<<endl;
                sum -= arr[l];
                l++;
            }
        }
    }
    if (ans == INT_MAX)
        return 0;

    return ans;
}

int main()
{
}