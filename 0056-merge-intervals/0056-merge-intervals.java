class Solution {

    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        ans.add(intervals[0]);
        for (int i = 1; i < n; i++) {
            int[] prev = ans.getLast();
            int[] curr = intervals[i];
            if (prev[1] >= curr[0]) {
                ans.removeLast();
                int[] temp = new int[] { prev[0], Math.max(prev[1], curr[1]) };
                ans.add(temp);
            } else {
                ans.add(intervals[i]);
            }
        }
        int[][] result = new int[ans.size()][2];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        return result;

    }
}