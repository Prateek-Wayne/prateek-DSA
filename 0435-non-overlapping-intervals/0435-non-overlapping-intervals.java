class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int count = 0;
        int lastTime = intervals[0][1];
        count++;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= lastTime) {
                lastTime = intervals[i][1];
                count++;
            }
        }
        return intervals.length - count;
    }
}