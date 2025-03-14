class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { solver(board); }

    bool solver(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solver(board))
                                return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
            // posX
            int posX = (row / 3) * 3;
            // posY
            int posY = (col / 3) * 3;
            int currX = posX + (i / 3);
            int currY = posY + (i % 3);
            if (board[currX][currY] == c)
                return false;
        }
        return true;
    }
};