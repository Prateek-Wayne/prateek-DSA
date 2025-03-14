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
        int n = board.size();

        // Check the current row on the left side
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true; // Safe to place the queen
    }
};