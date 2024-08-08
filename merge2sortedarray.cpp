#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = 0;
    int right = 0;
    //   vector<int> nums1={1,2,3,0,0,0};
    // vector<int> nums2={2,5,6};
    while (left < m && right < n)
    {
        if (nums1[left] < nums2[right])
        {
            left++;
        }
        else if (nums1[left] >= nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left++;
        }
        else
        {
            left++;
            right++;
        }
    }

    for (int i = left; i < m + n; i++)
    {   
        if((i-left)<n)
        nums1[i] = nums2[i-left];

    }
    cout<<endl;
    for(auto i:nums1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}
int main()
{

    // vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums1={1};
    // int m=3;
    int m=1;
    // int n=3;
    int n=0;

    [4,5,6,0,0,0]
3
[1,2,3]
3
    vector<int> nums2={};
    merge(nums1,m,nums2,n);

}