#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
  int count=1;
  int res=0;
  for(int i=1;i<nums.size();i++)
  {
    if(nums[i]==nums[res])
        count++;
    else
        count--;
    if(count==0)
    {
        count=1;
        res=i;
    }
  }
  return nums[res];
}
int main()
{
    vector<int> nums={1,1,1,1,7,4,5};
    cout<<majorityElement(nums);
}