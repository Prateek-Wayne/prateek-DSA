class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<m && j<n)
        {
            if(num1[i]<=num2[j])
            {
                ans.push_back(num1[i]);
                i++;
            }
            else
            {
                ans.push_back(num2[j]);
                j++;
            }
        }
        while(i<m)
        {
            ans.push_back(num1[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(num2[j]);
            j++;
        }
        num1=ans;
    }
};