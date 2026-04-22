class Solution {
 int[][] directions = new int[][] { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

    void dfs(char[][] board, int i, int j, boolean[][] visited) {
        int m = board.length;
        int n = board[0].length;
        for (int d = 0; d < directions.length; d++) {
            int newX = directions[d][0] + i;
            int newY = directions[d][1] + j;
            if (newX < 0 || newY < 0 || newX >= m || newY >= n)
                continue;
            if (visited[newX][newY])
                continue;
            if (board[newX][newY] == 'X')
                continue;
            if (board[newX][newY] == 'O') {
                visited[newX][newY] = true;
                dfs(board, newX, newY, visited);
            }
        }

    }

    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                visited[i][0] = true;
                dfs(board, i, 0, visited);
            }
            if (board[i][n - 1] == 'O') {
                visited[i][n - 1] = true;
                dfs(board, i, n - 1, visited);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                visited[0][i] = true;
                dfs(board, 0, i, visited);
            }
            if (board[m - 1][i] == 'O') {
                visited[m - 1][i] = true;
                dfs(board, m - 1, i, visited);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
        return;

    }
}