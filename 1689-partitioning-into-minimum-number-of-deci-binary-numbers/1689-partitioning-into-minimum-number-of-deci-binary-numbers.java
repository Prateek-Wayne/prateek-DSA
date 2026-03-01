class Solution {
  public int minPartitions(String n) {
        int maxy = 0;
        for (int i = 0; i < n.length(); i++) {
            int number = n.charAt(i) - '0';
            maxy = Math.max(maxy, number);
        }
        return maxy;
    }
}