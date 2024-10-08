#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> & nums,int k,int index,vector<int> &ds,int &sum,int &count)
{
    if(index==nums.size())
    {
        if(sum==k)
            count++;
        return;
    }
    // add condition...
    sum+=nums[index];
    ds.push_back(nums[index]);
    helper(nums,k,index+1,ds,sum,count);

    //pop conditon
    sum-=nums[index];
    ds.pop_back();
    helper(nums,k,index+1,ds,sum,count);
}

int subarraySum(vector<int> &nums, int k)
{
    int sum=0;
    vector<int> ds;
    int count=0;

    helper(nums,k,0,ds,sum,count);
    return count;

}
int main()
{
    return 0;
}