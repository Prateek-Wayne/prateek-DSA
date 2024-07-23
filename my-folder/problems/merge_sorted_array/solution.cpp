class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6] O(m+n);
        
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
                nums1[k--]=nums1[i--];
            else if(nums1[i]<nums2[j])
                nums1[k--]=nums2[j--];
        }
        while(i>=0)
            nums1[k--]=nums1[i--];
        while(j>=0)
            nums1[k--]=nums2[j--];
        return;
    }
};