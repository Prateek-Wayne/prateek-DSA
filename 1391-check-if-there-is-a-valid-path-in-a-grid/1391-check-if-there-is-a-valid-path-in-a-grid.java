class Solution {
 Map<Integer, int[][]> mp = new HashMap<>();

    boolean dfs(int[][] grid, boolean[][] visited, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;
        if (i == m - 1 && j == n - 1)
            return true;
        visited[i][j] = true;
        for (int[] dir : mp.get(grid[i][j])) {
            int newX = i + dir[0];
            int newY = j + dir[1];
            if (newX < 0 || newY < 0 || newX >= m || newY >= n || visited[newX][newY] == true)
                continue;
            for (int[] reversedir : mp.get(grid[newX][newY])) {
                if (newX + reversedir[0] == i && newY + reversedir[1] == j) {
                    if (dfs(grid, visited, newX, newY))
                        return true;
                }
            }
        }
        return false;
    }

    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        mp.put(1, new int[][] { { 0, -1 }, { 0, 1 } });
        mp.put(2, new int[][] { { -1, 0 }, { 1, 0 } });
        mp.put(3, new int[][] { { 0, -1 }, { 1, 0 } });
        mp.put(4, new int[][] { { 0, 1 }, { 1, 0 } });
        mp.put(5, new int[][] { { 0, -1 }, { -1, 0 } });
        mp.put(6, new int[][] { { 0, 1 }, { -1, 0 } });

        boolean[][] visited = new boolean[m][n];
        return dfs(grid, visited, 0, 0);

    }
}