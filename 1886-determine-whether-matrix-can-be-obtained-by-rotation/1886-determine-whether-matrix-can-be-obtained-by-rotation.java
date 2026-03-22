class Solution {
 public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        boolean r0 = true;
        boolean r90 = true;
        boolean r180 = true;
        boolean r270 = true;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j])
                    r0 = false;
                if (mat[n - j - 1][i] != target[i][j])
                    r90 = false;
                if (mat[n - i - 1][n - j - 1] != target[i][j])
                    r180 = false;
                if (mat[j][n - i - 1] != target[i][j])
                    r270 = false;
            }
        }
        return r0 || r90 || r180 || r270;
    }
}