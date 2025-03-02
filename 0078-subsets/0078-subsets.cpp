class Solution {
public:

  void helper(vector<int>& nums ,int i,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(i==(nums.size()))
        {
            ans.push_back(ds);
            return ;
        }
        // pick 
        ds.push_back(nums[i]);
        helper(nums,i +1,ds,ans);
        // not pick
        ds.pop_back();
        helper(nums,i+1,ds,ans);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>  ans={};
        vector<int> ds={};
         helper(nums,0,ds,ans);
         return ans;
    }
};