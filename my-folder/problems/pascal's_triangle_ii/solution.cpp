class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
         rowIndex=rowIndex+1;
        long long ans=1;
        row.push_back(ans);
        for(int i=1;i<rowIndex;i++)
        {
            ans=ans*(rowIndex-i);
            ans=ans/(i);
            row.push_back(ans);
        }
        return row;
    }
};