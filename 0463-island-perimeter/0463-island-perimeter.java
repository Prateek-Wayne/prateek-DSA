class Solution {
    void dfs(int[][] grid, int i, int j, int[] result) {
        int m = grid.length;
        int n = grid[0].length;
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            result[0]++;
            return;
        }
        if (grid[i][j] != -1) {
            grid[i][j] = -1;
            dfs(grid, i + 1, j, result);
            dfs(grid, i - 1, j, result);
            dfs(grid, i, j + 1, result);
            dfs(grid, i, j - 1, result);
        }
    }

    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] result = new int[] { 0 };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, result);
                }
            }
        }
        return result[0];
    }
}