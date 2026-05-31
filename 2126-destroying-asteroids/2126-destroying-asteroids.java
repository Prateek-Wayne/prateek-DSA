class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        Long newMass = (long)mass;
        for (int i : asteroids) {
            if (newMass < i) {
                return false;
            } else {
                newMass += i;
            }
        }
        return true;
    }
}