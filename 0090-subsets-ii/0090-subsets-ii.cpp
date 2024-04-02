class Solution {
public:
    


void recurssion(int index, vector<int> &ds, vector<int> &arr, vector<vector<int>> &result)
{
    if(index==arr.size())
    {   
        vector<int> ds_copy = ds;
        sort(ds_copy.begin(),ds_copy.end());
        result.push_back(ds_copy);
        return;
    }
    ds.push_back(arr[index]);
    recurssion(index+1,ds,arr,result);
    ds.pop_back();
    recurssion(index+1,ds,arr,result);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> ds;
    recurssion(0, ds, nums, result);
    set<vector<int>> st;

    for (auto i : result)
    {
        st.insert(i);
    }
    vector<vector<int>> ans;
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}
};