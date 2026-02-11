class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int maxy = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        for (j = 0; j < k; j++) {
            sum += cardPoints[j];
        }
        j--;
        maxy = Math.max(maxy, sum);
        for (i = n - 1; i >= 0 && j >= 0; i--, j--) {
            sum -= cardPoints[j];
            sum += cardPoints[i];
            maxy = Math.max(maxy, sum);
        }
        return maxy;
    }
}