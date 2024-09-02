#include <bits/stdc++.h>
using namespace std;

int findBreakPoint(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] < arr[n - 1])
        return 0; // No rotation
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid < n - 1 && arr[mid] > arr[mid + 1])
            return mid + 1;
        if (mid > 0 && arr[mid] < arr[mid - 1])
            return mid;
        if (arr[mid] >= arr[low])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int search(vector<int> &arr, int target)
{
    int n = arr.size();
    if (n == 1)
        return arr[0] == target ? 0 : -1;
    int breakPoint = findBreakPoint(arr);
    if (breakPoint == 0)
    {
        auto it = lower_bound(arr.begin(), arr.end(), target);
        return (it != arr.end() && *it == target) ? distance(arr.begin(), it) : -1;
    }

    auto it1 = lower_bound(arr.begin(), arr.begin() + breakPoint, target);
    if (it1 != arr.begin() + breakPoint && *it1 == target)
        return distance(arr.begin(), it1);

    auto it2 = lower_bound(arr.begin() + breakPoint, arr.end(), target);
    if (it2 != arr.end() && *it2 == target)
        return distance(arr.begin(), it2);

    return -1;
}

int main()
{ // vector<int> arr = {4,5,6,7,0,1,2};
     vector<int> arr = {1,3};
    cout << findBreakPoint(arr) << endl;
    cout << search(arr, 0);
}