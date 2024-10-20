#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums,int index,vector<int> &ds,set<vector<int>> &ans)
{
    if(index==nums.size())
    {
        sort(ds.begin(),ds.end());
        ans.insert(ds);
        return;
    }
    // add codntion....
    ds.push_back(nums[index]);
    helper(nums,index+1,ds,ans);
    // remove codntion...
    ds.pop_back();
    helper(nums,index+1,ds,ans);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> st;
    vector<int> ds;
    helper(nums,0,ds,st);
    vector<vector<int>> ans;
    for(auto i:st)
        ans.push_back(i);
    return ans;
}

int main()
{
    return 0;
}