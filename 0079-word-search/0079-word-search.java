class Solution {

    boolean helper(char[][] board, String word, int row, int col, int index) {
        if (index == word.length())
            return true;
        int m = board.length;
        int n = board[0].length;
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word.charAt(index))
            return false;
        char temp = board[row][col];
        board[row][col] = '#';
        boolean answer = helper(board, word, row, col + 1, index + 1) ||
                helper(board, word, row + 1, col, index + 1) ||
                helper(board, word, row - 1, col, index + 1) ||
                helper(board, word, row, col - 1, index + 1);
        board[row][col] = temp;
        return answer;

    }

    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (helper(board, word, i, j, 0) == true) {
                    return true;
                }
            }
        }
        return false;
    }
}