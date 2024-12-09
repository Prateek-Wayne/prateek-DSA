#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> & arr,vector<int> ds,int Sum,int target,int ind)
{
    // base...
    if(ind==arr.size())
    {
        if(Sum==target)
            return 1;
        return 0;
    }
    // add condition...
    Sum+=arr[ind];
    ds.push_back(arr[ind]);
    int left=helper(arr,ds,Sum,target,ind+1);

    // pop...
    Sum-=arr[ind];
    ds.pop_back();
    int right=helper(arr,ds,Sum,target,ind+1);
    return left+right;
}

 int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int> ds={};
        return helper(arr,ds,0,target,0);
    }

int main()
{   
    vector<int> arr={35, 2, 8, 22};
    cout<<perfectSum(arr,0);
 return 0;
}