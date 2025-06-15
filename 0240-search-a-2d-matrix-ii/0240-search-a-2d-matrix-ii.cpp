class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int tempRow = 0, tempCol = col - 1;
        while (tempRow < row && tempCol >= 0) {
            if (matrix[tempRow][tempCol] == target)
                return true;
            else if (matrix[tempRow][tempCol] > target) {
                tempCol--;
            } else
                tempRow++;
        }
        return false;
    }
};