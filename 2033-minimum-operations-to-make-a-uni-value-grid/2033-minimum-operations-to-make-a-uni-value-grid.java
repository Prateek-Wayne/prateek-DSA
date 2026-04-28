class Solution {
 public int minOperations(int[][] grid, int x) {
        List<Integer> ls = new ArrayList<>();
        for (int[] temp : grid) {
            for (int t : temp) {
                ls.add(t);
            }
        }
        // sort ls....
        ls.sort(null);
        // median...
        int median = ls.get(ls.size() / 2);
        int operations = 0;
        for (int i : ls) {
            int diff = Math.abs(i - median);
            if (diff % x != 0)
                return -1;
            operations += diff / x;
        }
        return operations;
    }
}