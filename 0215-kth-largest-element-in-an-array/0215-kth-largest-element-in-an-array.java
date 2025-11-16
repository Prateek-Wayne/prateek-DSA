class Solution {
  public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue=new PriorityQueue<>();
        for(int i=0;i<nums.length;i++){
            queue.add(nums[i]);
            while (queue.size()>k) {
                queue.poll();
            }
        }
        return queue.peek();
    }
}