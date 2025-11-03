class Solution {
    public int minCost(String colors, int[] neededTime) {
        int total = 0;
        for (int i = 1; i < colors.length(); i++) {
            if (colors.charAt(i - 1) == colors.charAt(i)) {
                total += Math.min(neededTime[i - 1], neededTime[i]);
                neededTime[i] = Math.max(neededTime[i], neededTime[i - 1]);
            }

        }
        return total;
    }
}