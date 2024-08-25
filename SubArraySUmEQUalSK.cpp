#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

void subarraySum(vector<int> &arr, int k) {
   int curr_sum=0;int ans=0;
   int n=arr.size();
   map<int,int> mp;
   mp[0]=1;
   for(int i=0;i<n;i++)
   {
    curr_sum+=arr[i];
    auto iter=mp.find(curr_sum-k);
    if(iter!=mp.end())
    {
        ans+=iter->second;
    }
    mp[curr_sum]++;
   }
   cout<<"ans"<< ans;
   //    return ans;
}

int main() {
    vector<int> nums = {1, -1,0};
    int k = 0;
    subarraySum(nums, k);
    return 0;
}