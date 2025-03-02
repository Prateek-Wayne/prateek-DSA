class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,vector<int> > mp;
        for(auto i:nums1)
            mp[i[0]].push_back(i[1]);
        for(auto i:nums2)
            mp[i[0]].push_back(i[1]);
        vector<vector<int>> ans;
        for(auto i:mp)
        {
            int sum=0;
            for(auto j:i.second)
                sum+=j;
            // vector<int> temp={i.first,sum};
            ans.push_back({i.first,sum});
        }
        return ans;

        
    }
};