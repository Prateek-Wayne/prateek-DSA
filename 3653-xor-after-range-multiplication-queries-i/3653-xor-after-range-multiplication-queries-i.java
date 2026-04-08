class Solution {
  public int xorAfterQueries(int[] nums, int[][] queries) {
        int modd = (int) 1e9 + 7;
        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for (int i = l; i <= r; i += k) {
                   nums[i] = (int) (((long) nums[i] * v) % modd);
            }
        }
        int xorr=nums[0];
        for(int i=1;i<nums.length;i++){
            xorr=xorr^nums[i];
        }
        return xorr;
    }
}