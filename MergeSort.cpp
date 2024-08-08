#include <bits/stdc++.h>
using namespace std;

void mergeMe(int arr[], int l, int m, int h)
{
    vector<int> temp;
    int left=l;
    int right = m + 1;
    while (l <= m && right <= h)
    {
        if (arr[l] <= arr[right])
        {
            temp.push_back(arr[l]);
            l++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (l <= m)
    {
        temp.push_back(arr[l]);
        l++;
    }
    while (right <= h)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = left; i <= h; i++)
    {
        arr[i] = temp[i-left];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
     int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergeMe(arr, l, mid, r);
}

int main()
{
      int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}