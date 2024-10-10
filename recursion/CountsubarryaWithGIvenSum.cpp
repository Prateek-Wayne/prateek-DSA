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

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int sum=0;
    vector<int> ds;
    int count=0;
    helper(arr,k,0,ds,sum,count);
    if(count>0)
        return true;
    return false;
}
int main()
{
    return 0;
}