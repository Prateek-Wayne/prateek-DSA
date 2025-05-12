class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp ;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int toFind=target-nums[i];
            if(mp.count(toFind) && mp[toFind]!=i){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(mp[toFind]);
                sort(temp.begin(),temp.end());
                return temp;
            }
        }
        return ans;
    }
};