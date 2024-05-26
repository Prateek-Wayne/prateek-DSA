class Solution {
public:
   
void recursion(vector<int>& a, int i, vector<int> ds,vector<vector<int>> &ans) {
    // base condition
    if (a.size() == i) {
        ans.push_back(ds);
        return;
    }
    // pick condition...
    ds.push_back(a[i]);
    recursion(a, i+1, ds, ans);
    // do not pick condition...
    ds.pop_back();
    recursion(a, i+1, ds,ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion(nums,0,{},ans);
        return ans;
    }
};