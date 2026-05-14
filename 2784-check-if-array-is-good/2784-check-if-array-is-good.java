class Solution {
    // int n=nums.length-1;
    // int x=nums[0];
    // for(int i=1;i<=n;i++){
    //     x=x^nums[i];
    // }
    // return x==n;
    public boolean isGood(int[] nums) {
        int base = nums.length - 1;
        List<Integer> nums1 = new ArrayList<>();
        for (int num : nums) {
            nums1.add(num);
        }
        nums1.sort(null);
        List<Integer> nums2 = new ArrayList<>();
        for (int i = 1; i <= base; i++) {
            nums2.add(i);
            if (i == base)
                nums2.add(i);
        }
        return nums1.equals(nums2);

    }
}