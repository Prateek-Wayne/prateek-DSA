class Solution {
  public double angleClock(int hour, int minutes) {
        double angle = (double) ((60 * hour) - (11 * minutes)) / 2;
        angle = Math.abs(angle);
        if (angle > 180)
            angle = 360 - angle;
        return angle;
    }
}