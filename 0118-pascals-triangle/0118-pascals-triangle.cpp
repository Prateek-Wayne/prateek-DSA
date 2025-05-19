class Solution {
public:

    vector<int> generateRow(int n){
        vector<int> arr;
        int ans=1;
        arr.push_back(ans);
        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans=ans/i;
            arr.push_back(ans);
        }
        return arr;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp=generateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};