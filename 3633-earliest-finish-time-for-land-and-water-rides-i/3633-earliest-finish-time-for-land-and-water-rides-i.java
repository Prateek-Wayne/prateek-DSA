class Solution {
    int solve(int[] firstStartTime, int[] firstDuration, int[] secondStartTime, int[] secondDuration) {
        int firstResult = Integer.MAX_VALUE;
        for (int i = 0; i < firstStartTime.length; i++) {
            int duration = firstStartTime[i] + firstDuration[i];
            firstResult = Math.min(firstResult, duration);
        }
        int secondResult = Integer.MAX_VALUE;
        for (int i = 0; i < secondStartTime.length; i++) {
            int duration = Math.max(secondStartTime[i], firstResult) + secondDuration[i];
            secondResult = Math.min(secondResult, duration);
        }
        return secondResult;
    }

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int firstLandSlide = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int firstWaterSlide = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return Math.min(firstLandSlide, firstWaterSlide);
    }
}