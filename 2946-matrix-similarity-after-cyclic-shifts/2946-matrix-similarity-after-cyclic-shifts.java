class Solution {

    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        k = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newCol = j;
                if (i % 2 == 0) {
                    newCol = (j + k) % n;
                } else {
                    newCol = (n - k + j) % n;
                }
                if (mat[i][j] != mat[i][newCol])
                    return false;

            }
        }
        return true;
    }
}