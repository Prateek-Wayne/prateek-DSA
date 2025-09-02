class Solution {
  Boolean calculate(int[] weights, int days, int weight) {
        int checkDays = 1;
        int sum = 0;
        for (int i = 0; i < weights.length; i++) {

            if (sum + weights[i] <= weight) {
                sum += weights[i];
            } else {
                checkDays++;
                sum = 0;
                sum += weights[i];
            }
        }
        return checkDays <= days;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();
        int ans = high;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (calculate(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
}