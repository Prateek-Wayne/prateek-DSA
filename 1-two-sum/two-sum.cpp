class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
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
};