class Solution {
  boolean isSafe(int x, int y, int m, int n) {
        return !(x >= m || y >= n || x < 0 || y < 0);
    }

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {

        int m = grid.size();
        int n = grid.get(0).size();
        int[][] result = new int[m][n];
        int[][] direction = new int[][] { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
        for (int[] r : result)
            Arrays.fill(r, Integer.MAX_VALUE);
            
        result[0][0] = grid.get(0).get(0);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[] { result[0][0], 0, 0 });
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int X = top[1];
            int Y = top[2];
            int dist = top[0];
            for (int[] dir : direction) {
                int x = X + dir[0];
                int y = Y + dir[1];
                if (isSafe(x, y, m, n)) {
                    int d = dist + grid.get(x).get(y);
                    if (result[x][y] > d) {
                        result[x][y] = d;
                        pq.add(new int[] { d, x, y });
                    }
                }
            }

        }
        return result[m - 1][n - 1] < health;
    }
}