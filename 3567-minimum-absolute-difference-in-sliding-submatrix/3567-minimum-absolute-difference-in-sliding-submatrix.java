class Solution {
public int[][] minAbsDiff(int[][] grid, int k) {
    int m = grid.length;
    int n = grid[0].length;

    int[][] ans = new int[m - k + 1][n - k + 1];

    for (int i = 0; i <= m - k; i++) {
        for (int j = 0; j <= n - k; j++) {

            TreeSet<Integer> set = new TreeSet<>();

            // collect k x k elements
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    set.add(grid[x][y]);
                }
            }

            int minAbs = Integer.MAX_VALUE;
            Integer prev = null;

            for (int val : set) {
                if (prev != null) {
                    minAbs = Math.min(minAbs, val - prev);
                }
                prev = val;
            }

            ans[i][j] = (minAbs == Integer.MAX_VALUE) ? 0 : minAbs;
        }
    }

    return ans;
}
}