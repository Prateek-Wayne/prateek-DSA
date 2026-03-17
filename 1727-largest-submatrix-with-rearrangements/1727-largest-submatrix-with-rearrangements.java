class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int ans = 0;
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                temp.add(matrix[i][j]);
            }
            temp.sort((a, b) -> b - a);
            for (int j = 0; j < n; j++) {
                int base = j + 1;
                int height = temp.get(j);
                ans = Math.max(ans, base * height);
            }
        }
        return ans;
    }
}