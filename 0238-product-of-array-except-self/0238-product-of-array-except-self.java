class Solution {
    public int[] productExceptSelf(int[] nums) {
          int countZero = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0)
                countZero++;
        }
        if (countZero > 1) {
            return new int[nums.length];
        }
        int product = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0)
                continue;
            product = product * nums[i];
        }
        if (countZero == 1) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == 0) {
                    nums[i] = product;
                }
                else{
                    nums[i]=0;
                }
            }
            return nums;
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = product / nums[i];
        }
        return nums;
    }
}