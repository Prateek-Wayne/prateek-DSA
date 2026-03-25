class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        long total = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int[] temp : grid) {
            for (int x : temp)
                total += x;
        }
        if (total % 2 != 0)
            return false;
        long sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == total / 2)
                return true;
        }
        sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[j][i];
            }
            if (sum == total / 2)
                return true;
        }
        return false;
    }
}