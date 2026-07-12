class Solution {
 public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> temp = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            temp.add(intervals[i]);
        }
        temp.add(newInterval);
        temp.sort((a, b) -> a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        ans.add(temp.get(0));
        for (int i = 1; i < temp.size(); i++) {
            if (ans.getLast()[1] >= temp.get(i)[0]) {
                ans.getLast()[1] = Math.max(ans.getLast()[1], temp.get(i)[1]);
            } else {
                ans.add(temp.get(i));
            }
        }
        int[][] result = new int[ans.size()][2];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        return result;
    }
}