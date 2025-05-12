class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto i:nums)
            ans=i^ans;
        ans=ans^0;
        return ans;
    }
};