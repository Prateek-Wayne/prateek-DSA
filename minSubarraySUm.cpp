#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
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
                // cout << "Ans value at" << l << "," << r << ":" << ans << endl;
                sum -= arr[l];
                l++;
            }
        }
    }
    if (ans == INT_MAX)
        return 0;

    return ans;
}

int minSubarray(vector<int> &arr, int p)
{
    long long sum = 0;
    for (auto i : arr)
        sum += i;
    if (sum % p == 0)
        return 0;
    int quotient = sum % p;
    int ans = INT_MAX;
    for (int i = 0; i < p; i++)
    {
        int target = quotient + p * i;
        int len = minSubArrayLen(target, arr);
        if (len != -1)
            ans = min(ans, len);
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}
int main()
{
    vector<int> arr={2, 3, 1, 2, 4, 3};
    int target = 7;
    minSubArrayLen(target, arr);
}