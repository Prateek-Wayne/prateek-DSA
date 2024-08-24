#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
       auto targetElement=mp.find(target-arr[i]);
       if(targetElement!=mp.end())
       {
            return {i,targetElement->second};
       }
       mp[arr[i]]=i;
    }
    return {-1,-1};

}

int main()
{
//    vector<int> arr={2,7,11,15};
   vector<int> arr={3,3};
//    vector<int> arr={2,7,11,15};
   vector<int> ans=twoSum(arr,6);
   for(auto i:ans)
    cout<<i<<"|";
//    vector<int> arr={1,1,1,2,2,3,4,5};
//    map<int,int> mp;
//    for(int i=0;i<arr.size();i++)
//    {
//        mp[arr[i]]++;
//    }

//    auto searchMe=mp.find(3);
//    cout<<searchMe->;
    // cout<<mp.find(3)

}