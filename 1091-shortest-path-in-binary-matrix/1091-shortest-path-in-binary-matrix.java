class Solution {

    boolean isSafe(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] result = new int[m][n];
        for (int i = 0; i < m; i++) {
            int[] temp = new int[n];
            Arrays.fill(temp, Integer.MAX_VALUE);
            result[i] = temp;
        }
        if (grid[0][0] != 0)
            return -1;
        result[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[][] directions = { { -1, 0 }, { -1, -1 }, { 0, -1 }, { 0, 1 }, { 1, 0 }, { 1, 1 }, { -1, 1 },
                { 1, -1 } };
        pq.add(new int[] { 0, 0, 0 });
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int w = top[0];
            int x = top[1];
            int y = top[2];
            for (int[] dir : directions) {
                int newX = dir[0] + x;
                int newY = dir[1] + y;
                if (isSafe(newX, newY, m, n)) {
                    int newDist = 1 + w;
                    if (grid[newX][newY] == 0 && result[newX][newY] > newDist) {
                        result[newX][newY] = newDist;
                        pq.add(new int[] { newDist, newX, newY });
                    }
                }
            }
        }
        if (result[m - 1][n - 1] == Integer.MAX_VALUE)
            return -1;
        return result[m - 1][n - 1]+1;
    }
}