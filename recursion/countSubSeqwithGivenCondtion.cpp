#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int target,int index,vector<int> &ds,int &sum)
{
    if(index==nums.size()){
        if(sum==target)
            return 1;
        return 0;
    }

    // add condtion..
    ds.push_back(nums[index]);
    sum+=nums[index];
    int left=helper(nums,target,index+1,ds,sum);

    // pop condition.
    ds.pop_back();
    sum-=nums[index];
    int right=helper(nums,target,index+1,ds,sum);
    return left+right;

}

int numSubseq(vector<int> &nums, int target)
{
    vector<int> ds;
    int sum=0;
    return helper(nums,target,0,ds,sum);

}
int main()
{   vector<int> nums={3,1,2};
    cout<<numSubseq(nums,2);
    return 0;
}