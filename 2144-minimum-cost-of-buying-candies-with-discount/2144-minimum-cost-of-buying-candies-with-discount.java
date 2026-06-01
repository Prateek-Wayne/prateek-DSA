class Solution {
 public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int ans = 0;
        int n = cost.length;
        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (count == 2) {
                count = 0;
                continue;
            }
            ans += cost[i];
            count++;
        }
        return ans;

    }
}