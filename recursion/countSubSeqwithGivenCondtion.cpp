#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int target,int index,vector<int> &ds,int &sum)
{   
    int mod=1e9;
   if(index==nums.size())
    {
        if(sum<=target && ds.size()>0)
            return 1;
        return 0;
    }
    // add condition...
    ds.push_back(nums[index]);
    sum+=(ds[0]+ds[ds.size()-1])%mod;
    int left=helper(nums,target,index+1,ds,sum);

    //remove cidntion...
    sum-=(ds[0]+ds[ds.size()-1]);
    ds.pop_back();
    int right=helper(nums,target,index+1,ds,sum);
    return (left + right);
}

int numSubseq(vector<int> &nums, int target)
{   sort(nums.begin(),nums.end());
    vector<int> ds;
    int sum=0;
    return helper(nums,target,0,ds,sum);

}
int main()
{   vector<int> nums={3,5,6,7};
    cout<<numSubseq(nums,9);
    return 0;
}