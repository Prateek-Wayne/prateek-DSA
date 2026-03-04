class Solution {
boolean checkValid(int i, int j, int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        int tempI = i;
        int tempJ = j;
        // top....
        while (tempI >= 0) {
            if (tempI != i) {
                if (mat[tempI][tempJ] == 1)
                    return false;
            }
            tempI--;
        }
        tempI = i;
        tempJ = j;
        // bottom...
        while (tempI < m) {
            if (tempI != i) {
                if (mat[tempI][tempJ] == 1)
                    return false;
            }
            tempI++;
        }
        // left...
        tempI = i;
        tempJ = j;
        while (tempJ >= 0) {
            if (tempJ != j) {
                if (mat[tempI][tempJ] == 1)
                    return false;
            }
            tempJ--;
        }
        // right...
        tempI = i;
        tempJ = j;
        while (tempJ < n) {
            if (tempJ != j) {
                if (mat[tempI][tempJ] == 1)
                    return false;
            }
            tempJ++;
        }

        return true;

    }

    public int numSpecial(int[][] mat) {
        int count = 0;
        int m = mat.length;
        int n = mat[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (checkValid(i, j, mat) == true)
                        count++;
                }
            }
        }
        return count;
    }
}