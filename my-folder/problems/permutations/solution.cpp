class Solution {
public:
    
void recurssion(vector<int> &ds,vector<bool>&mp ,vector<int> &arr,vector<vector<int>> &result)
{
    // base condtion..
    if(ds.size()==arr.size())
    {
        result.push_back(ds);
        return;
    }
    // take all one by one using for loop...
    for(int i=0;i<arr.size();i++)
    {
        // check if not exisit ...
        if(!mp[i])
        {
            ds.push_back(arr[i]);
            mp[i]=true;
            recurssion(ds,mp,arr,result);
            // rmove them
            ds.pop_back();
            mp[i]=false;
        }        
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> result;
        vector<bool> mp(nums.size(),false);
        recurssion(ds,mp,nums,result);
        return result;
    }
};