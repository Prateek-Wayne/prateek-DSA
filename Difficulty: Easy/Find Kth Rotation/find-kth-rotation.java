class Solution {
 public int findKRotation(int arr[]) {
        int[] pair = new int[] { Integer.MAX_VALUE, -1 };
        int low = 0;
        int high = arr.length-1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (arr[low] <= arr[mid])// left is sorted...
            {
                if (arr[low] < pair[0]) {
                    pair[0] = arr[low];
                    pair[1] = low;
                }
                low = mid + 1;
            } else { // right is sorted
                if (arr[mid] < pair[0]) {
                    pair[0] = arr[mid];
                    pair[1] = mid;
                }
                high = mid - 1;
            }
        }
        return pair[1];
    }
}