class Solution {
public:
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    helper(board, 0, ans);
    return ans;
}
void helper(vector<string> &board, int col, vector<vector<string>> &ans)
{
    int n = board.size();
    // base case..
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {

        if (issafe(board, i, col))
        {
            board[i][col] = 'Q';
            helper(board, col + 1, ans);
            board[i][col] = '.';
        }
    }
}

bool issafe(vector<string> &board, int row, int col)
{
    int n = board.size();
    int tempRow = row;
    int tempCol = col;
    while (tempRow >= 0 && tempCol >= 0)
    {
        if (board[tempRow][tempCol] == 'Q')
            return false;
        tempRow--;
        tempCol--;
    }
    tempRow = row, tempCol = col;
    while (tempRow < n && tempCol >= 0)
    {
        if (board[tempRow][tempCol] == 'Q')
            return false;
        tempRow++;
        tempCol--;
    }
    tempRow = row;
    tempCol = col;
    while (tempCol >= 0)
    {
        if (board[tempRow][tempCol] == 'Q')
            return false;
        tempCol--;
    }
    return true;
}
};