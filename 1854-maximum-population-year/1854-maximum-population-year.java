class Solution {
    public int maximumPopulation(int[][] logs) {
        List<int[]> events = new ArrayList<>();
        for (int[] log : logs) {
            events.add(new int[] { log[0], 1 });
            events.add(new int[] { log[1], -1 });
        }
        // events.sort((a, b) -> a[0] - b[0]);
        events.sort((a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        });
        int sum = 0;
        int[] ans = new int[] { 0, 1950 };
        for (int[] e : events) {
            sum += e[1];
            if (sum > ans[0]) {
                ans[0] = sum;
                ans[1] = e[0];
            }
        }
        return ans[1];
    }
}