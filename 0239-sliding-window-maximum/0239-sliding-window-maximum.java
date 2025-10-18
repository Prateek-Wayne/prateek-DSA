class Solution {
public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        Deque<Integer> deque = new ArrayDeque<>();
        int ansIndex = 0;
        
        int i = 0, j = 0;
        
        while (j < n) {
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[j]) {
                deque.pollLast();
            }
            
            deque.addLast(j);
            
            if (j - i + 1 == k) {
                ans[ansIndex++] = nums[deque.peekFirst()];
            
                if (deque.peekFirst() == i) {
                    deque.pollFirst();
                }
                
                i++; 
            }
            
            j++;
        }
        
        return ans;
    }
}