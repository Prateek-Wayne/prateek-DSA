class Solution {
public:
    void findCombination(int index,int target,vector<int> &arr ,vector<vector<int>> &res,vector<int> &ans)
{
    if(index==arr.size())
    {
        if(target==0)
        {
            res.push_back(ans);
        }
            return;
    }
    if(arr[index] <= target)
    {
    // tick condition
    ans.push_back(arr[index]);
    findCombination(index,target-arr[index],arr,res,ans);
    ans.pop_back();
    }
    findCombination(index+1,target,arr,res,ans);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }
};