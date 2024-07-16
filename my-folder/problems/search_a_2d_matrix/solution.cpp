class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int row=matrix.size();
        int cols=matrix[0].size();
        int high=row*cols-1;
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            int trow=mid/cols;
            int tcol=mid%cols;
            if(matrix[trow][tcol]==target)
                return true;
            if(matrix[trow][tcol]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};