class Solution {
    boolean isSafe(int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int m = image.length;
        int n = image[0].length;
        int original = image[sr][sc];
        if (original == color)
            return image;

        int[][] dirs = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { sr, sc });
        image[sr][sc] = color;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int[] d : dirs) {
                int nx = cur[0] + d[0], ny = cur[1] + d[1];
                if (isSafe(m, n, nx, ny) && image[nx][ny] == original) {
                    image[nx][ny] = color;
                    q.add(new int[] { nx, ny });
                }
            }
        }
        return image;
    }
}