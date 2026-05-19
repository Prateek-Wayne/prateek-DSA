class Solution {
    boolean isSafe(int m, int n, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n)
            return false;
        return true;
    }

    public int orangesRotting(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();
        int m = grid.length, n = grid[0].length;
        int fresh = 0, minutes = 0;
        int[][] directions = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.add(new int[] { i, j });
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;

        while (!q.isEmpty() && fresh > 0) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                int[] cur = q.poll();
                for (int[] dir : directions) {
                    int nx = cur[0] + dir[0], ny = cur[1] + dir[1];
                    if (isSafe(m, n, nx, ny) && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.add(new int[] { nx, ny });
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
}