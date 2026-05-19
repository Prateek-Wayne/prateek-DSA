class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                if(nums1[i]==nums2[j])
                    return nums1[i];
                if(nums2[j]>nums1[i])
                    break;
            }
        }
        return -1;
    }
}