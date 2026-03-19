class Solution {
 public boolean isValidSudoku(char[][] board) {
        HashSet<String> st = new HashSet<>();
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                String row = "row_" + i + "_" + board[i][j];
                String col = "col_" + j + "_" + board[i][j];
                String grid = "grid_" + i / 3 + "|" + j / 3 + "_" + board[i][j];
                if (st.contains(row) || st.contains(col) || st.contains(grid))
                    return false;
                st.add(row);
                st.add(col);
                st.add(grid);
            }
        }
        return true;
    }
}