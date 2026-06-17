class Solution {
 int findGollaIndex(int[] nums) {
        int gollaIndex = -1;
        int n = nums.length;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                gollaIndex = i - 1;
                break;
            }
        }
        return gollaIndex;
    }

    int findSwapIndex(int[] nums, int gollaIndex) {
        int n = nums.length;
        int swapIndex = n - 1;
        for (int i = n - 1; i > gollaIndex; i--) {
            if (nums[i] > nums[gollaIndex]) {
                swapIndex = i;
                break;
            }
        }
        return swapIndex;
    }

    void reverse(int[] nums, int gollaIndex) {
        int start = gollaIndex + 1;
        int end = nums.length - 1;
        while (start <= end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        return;
    }

    public void nextPermutation(int[] nums) {
        int gollaIndex = findGollaIndex(nums);
        if (gollaIndex != -1) {
            int swapIndex = findSwapIndex(nums, gollaIndex);
            System.out.println(gollaIndex);
            System.out.println(swapIndex);
            int temp = nums[gollaIndex];
            nums[gollaIndex] = nums[swapIndex];
            nums[swapIndex] = temp;
        }
        reverse(nums, gollaIndex);
        return;
    }
}