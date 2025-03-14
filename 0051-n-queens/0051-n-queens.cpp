class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        helper(board, ans, 0);
        return ans;
    }

    void helper(vector<string>& board, vector<vector<string>>& ans, int col) {
        int n = board.size();
        if (col == n) {
            ans.push_back(board);
            return;
        }
        //
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                helper(board, ans, col + 1);
                board[row][col] = '.';
            }
        }
        return;
    }

    bool isSafe(vector<string>& board, int row, int col) {
        int tempRow = row, tempCol = col, n = board.size();
        while (tempRow >= 0 && tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q')
                return false;
            tempRow--;
            tempCol--;
        }
        tempRow = row;
        tempCol = col;
        while (tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q')
                return false;
            tempCol--;
        }
        tempRow = row;
        tempCol = col;
        while (tempRow < n && tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q')
                return false;
            tempRow++;
            tempCol--;
        }
        return true;
    }
};