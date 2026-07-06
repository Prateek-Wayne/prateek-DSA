class Solution {
 public static int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return b[1] - a[1];
            }
        });
        List<int[]> arr = new ArrayList<>();
        for (int[] i : intervals) {
            arr.add(i);
        }
        int i = 1;
        while (i != arr.size()) {
            int[] p = arr.get(i - 1);
            int[] q = arr.get(i);
            if (q[0] <= p[0] && p[1] <= q[1]) {
                arr.remove(i-1);
                continue;
            } else if (p[0] <= q[0] && q[1] <= p[1]) {
                arr.remove(i );
                continue;
            }
            i++;
        }
        return arr.size();
    }
}