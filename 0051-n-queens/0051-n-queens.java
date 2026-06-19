class Solution {
    public boolean isSafe(List<StringBuilder> board, int i, int j) {
        int n = board.size();
        // check row ...

        for (int c = 0; c < j; c++) {
            if (board.get(i).charAt(c) == 'Q')
                return false;
        }
        // upper-left diagonal
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
            if (board.get(row).charAt(col) == 'Q')
                return false;
        }
        // lower-left diagonal
        for (int row = i + 1, col = j - 1; row < n && col >= 0; row++, col--) {
            if (board.get(row).charAt(col) == 'Q')
                return false;
        }
        return true;
    }

    public void helper(List<StringBuilder> board, List<List<String>> ans, int col) {
        int n = board.size();
        if (n == col) {
            List<String> temp = new ArrayList<>();
            for (StringBuilder s : board) {
                temp.add(s.toString());
            }
            ans.add(new ArrayList<>(temp));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col)) {
                board.get(i).setCharAt(col, 'Q');
                helper(board, ans, col + 1);
                board.get(i).setCharAt(col, '.');
            }
        }
        return;
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        List<StringBuilder> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder s = new StringBuilder();
            for (int c = 0; c < n; c++)
                s.append('.');
            board.add(s);
        }

        helper(board, ans, 0);
        return ans;
    }
}