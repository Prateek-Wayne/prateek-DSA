#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums)
{
    int low=0;
    int mid=0;
    int high=nums.size()-1;

    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
            mid++;
        }
    }
    for(auto i:nums)
    {
        cout<<i<<" ";
    }
}

int main()
{
    // vector<int> nums={1,1,1,2,2,2,0,0,0,2};
    vector<int> nums={2,0,2,1,1,0};
    sortColors(nums);
    return 0;
}