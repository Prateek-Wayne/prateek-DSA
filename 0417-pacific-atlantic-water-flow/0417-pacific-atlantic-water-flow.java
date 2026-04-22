class Solution {

    int[][] directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int[][] heights, int i, int j, boolean[][] visited) {
        visited[i][j] = true;

        for (int[] d : directions) {
            int x = i + d[0];
            int y = j + d[1];

            if (x < 0 || y < 0 || x >= heights.length || y >= heights[0].length)
                continue;

            if (visited[x][y]) continue;

            if (heights[x][y] >= heights[i][j]) {
                dfs(heights, x, y, visited);
            }
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {

        int m = heights.length, n = heights[0].length;

        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];

        // Pacific (top + left)
        for (int i = 0; i < m; i++) dfs(heights, i, 0, pacific);
        for (int j = 0; j < n; j++) dfs(heights, 0, j, pacific);

        // Atlantic (bottom + right)
        for (int i = 0; i < m; i++) dfs(heights, i, n - 1, atlantic);
        for (int j = 0; j < n; j++) dfs(heights, m - 1, j, atlantic);

        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }

        return result;
    }
}