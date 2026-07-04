class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ds = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        ds.add(intervals[0]);
        for (int i = 1; i < intervals.length; i++) {
            int[] temp = intervals[i];
            if (temp[0] <= ds.getLast()[1]) {
                ds.getLast()[1] = Math.max(temp[1], ds.getLast()[1]);
            } else
                ds.add(temp);
        }
        int[][] ans = new int[ds.size()][2];
        for (int i = 0; i < ds.size(); i++) {
            ans[i] = ds.get(i);
        }
        return ans;
    }
}