#include<bits/stdc++.h>
using namespace std;


int maxLen(vector<int>& arr, int n) {
    int curr_sum=0;
    int ans=0;
    map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(mp.find(curr_sum+arr[i])!=mp.end())
        {
            auto iter=mp.find(curr_sum+arr[i]);
            ans=max(ans,i-iter->second);
            curr_sum+=arr[i];
        }
        else{
            curr_sum+=arr[i];
            mp[curr_sum]=i;
        }
    }
    return ans;

}

int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here
    int n=arr.size();
     long long curr_sum=0;
    int ans=0;
    map<long long,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(mp.find(curr_sum+arr[i]-k)!=mp.end())
        {
            auto iter=mp.find(curr_sum+arr[i]);
            ans=max(ans,i-iter->second);
            curr_sum+=arr[i];
        }
        else{
            curr_sum+=arr[i];
            mp[curr_sum]=i;
        }
    }
    return ans;

}



int main()
{
    // vector<int> arr= {15,-2,2,-8,1,7,10,23};
    // vector<int> arr= {2,10,4};
    // vector<int> arr= {1, 0, -4, 3, 1, 0};
    // vector<int> arr= {1 ,2 ,3, 1, 1, 1, 1};
    vector<int> arr= {1 ,2 ,1,3};
    // cout<<maxLen(arr,arr.size());
    cout<<longestSubarrayWithSumK(arr,2);

}