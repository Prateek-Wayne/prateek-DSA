class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>> &arr)
{   
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++)
    {
        if(!ans.empty() && arr[i][0]<=ans.back()[1])
        {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
   
    

}
};