class Solution {
    int[] leftRotate(int[] temp) {
        int first = temp[0];
        int n = temp.length;
        for (int i = 1; i < n; i++) {
            temp[i - 1] = temp[i];
        }
        temp[n - 1] = first;
        return temp;
    }

    int[] rightRotate(int[] temp) {
        int n = temp.length;
        int last = temp[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            temp[i + 1] = temp[i];
        }
        temp[0] = last;
        return temp;
    }

    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        k = k % n;
        int[][] copyOfMat = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                copyOfMat[i][j] = mat[i][j];
        }
        for (int i = 0; i < k; i++) {
            for (int r = 0; r < m; r++) {
                int[] temp = copyOfMat[r];
                if (r % 2 == 0) {
                    temp = leftRotate(temp);
                } else
                    temp = rightRotate(temp);
                copyOfMat[r] = temp;
            }
        }
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (copyOfMat[i][j] != mat[i][j])
                    return false;
        }
        return true;

    }
}