
class NumMatrix {

    int[][] matrix;
    int r;
    int c;
    int[][] p;

    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;
        this.r = matrix.length;
        this.c = matrix[0].length;
        this.p = new int[r][c];

        calculatePrfixSum();
    }

    public void calculatePrfixSum() {
        p[0][0] = matrix[0][0];
        for (int i = 1; i < r; i++) {
            p[i][0] = p[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < c; i++) {
            p[0][i] = p[0][i - 1] + matrix[0][i];
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                p[i][j] = p[i - 1][j] + p[i][j - 1] + matrix[i][j] - p[i - 1][j - 1];
            }
        }
    }

public int sumRegion(int row1, int col1, int row2, int col2) {
    int total = p[row2][col2];
    int left = (col1 > 0) ? p[row2][col1 - 1] : 0;
    int top = (row1 > 0) ? p[row1 - 1][col2] : 0;
    int topLeft = (row1 > 0 && col1 > 0) ? p[row1 - 1][col1 - 1] : 0;
    return total - left - top + topLeft;
}
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */