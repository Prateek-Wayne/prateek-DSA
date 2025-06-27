class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] arr = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            int toFind = target - nums[i];
            if (map.containsKey(toFind)) {
                int first = i;
                int second = map.get(toFind);
                if (first < second) {
                    arr[0] = first;
                    arr[1] = second;
                    break;
                }

            }
        }
        return arr;

    }
}