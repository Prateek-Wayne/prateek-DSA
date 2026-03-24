class Solution {
public:
    int searchCols(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[row - 1][col - 1])
            return -1;

        int low = 0, high = row - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0, high = col - 1;
        int rowToFind = searchCols(matrix, target);
        if (rowToFind == -1)
            return false;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[rowToFind][mid] == target)
                return true;
            else if (matrix[rowToFind][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};