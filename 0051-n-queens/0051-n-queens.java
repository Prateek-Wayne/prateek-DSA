class Solution {
   boolean isSafe(List<StringBuilder> board, int row, int col) {
        int newRow = row - 1;
        int newCol = col - 1;
        while (newRow >= 0 && newCol >= 0) {
            if (board.get(newRow).charAt(newCol) == 'Q')
                return false;
            newRow--;
            newCol--;
        }
        newRow = row + 1;
        newCol = col - 1;
        while (newRow < board.size() && newCol >= 0) {
            if (board.get(newRow).charAt(newCol) == 'Q')
                return false;
            newRow++;
            newCol--;
        }
        newRow = row;
        newCol = col - 1;
        while (newCol >= 0) {
            if (board.get(row).charAt(newCol) == 'Q')
                return false;
            newCol--;
        }
        return true;

    }

    void helper(int n, List<StringBuilder> board, List<List<String>> ans, int column) {
        if (column == n) {
            ans.add(board.stream().map(StringBuilder::toString).toList());
            return;
        }
        // is safe...
        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, column)) {
                board.get(i).setCharAt(column, 'Q');
                helper(n, board, ans, column + 1);
                board.get(i).setCharAt(column, '.');
            }
        }
        return;
    }

    public List<List<String>> solveNQueens(int n) {
        List<StringBuilder> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder st = new StringBuilder();
            for (int j = 0; j < n; j++) {
                st.append('.');
            }
            board.add(st);
        }
        List<List<String>> ans = new ArrayList<>();
        helper(n, board, ans, 0);
        return ans;
    }
}