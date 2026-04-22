class Solution {
    boolean isSafe(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Queue<int[]> pq = new LinkedList<>();
        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    pq.add(new int[] { i, j });
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }
        if (freshOranges == 0) return 0;
        int minutes = 0;
        int[][] directions = new int[][] { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
        while (!pq.isEmpty()) {
            int size = pq.size();
            while (size != 0) {
                int[] top = pq.poll();
                int x = top[0];
                int y = top[1];
                for (int[] dir : directions) {
                    int newX = dir[0] + x;
                    int newY = dir[1] + y;
                    if (isSafe(newX, newY, m, n) && grid[newX][newY] != 0 && grid[newX][newY] != 2) {
                        grid[newX][newY] = 2;
                        pq.add(new int[] { newX, newY });
                        freshOranges--;
                    }
                }
                size--;
            }
            minutes++;
        }
        return freshOranges == 0 ? minutes - 1 : -1;
    }
}