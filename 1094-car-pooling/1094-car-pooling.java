class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        List<int[]> events = new ArrayList<>();
        for (int[] t : trips) {
            events.add(new int[] { t[1], t[0] });
            events.add(new int[] { t[2], -t[0] });
        }
        int sum = 0;
        events.sort((a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        });
        for (int[] e : events) {
            sum += e[1];
            if (sum > capacity)
                return false;
        }
        return true;
    }
}