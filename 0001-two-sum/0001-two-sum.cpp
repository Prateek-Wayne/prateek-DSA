class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int toFind=(target-nums[i]);
            if(mp.count(toFind) && i != mp[toFind]){
                return {i,mp[toFind]};
            }
        }
        return {};
    }
};