import java.util.*;

class Solution {
     public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int i = 0;
        int j = k - 1;
        while (j < n) {
            Map<Integer, Integer> mp = new HashMap<>(); // Changed to HashMap for frequency counting
            int start = i;
            int sum = 0;
            for (; start <= j; start++) {
                sum += nums[start];
                mp.put(nums[start], mp.getOrDefault(nums[start], 0) + 1);
            }
            if (mp.size() < x) {
                ans[j - k + 1] = sum;
            } else {

                List<Map.Entry<Integer, Integer>> entries = new ArrayList<>(mp.entrySet());
                entries.sort((a, b) -> {
                    if (!a.getValue().equals(b.getValue())) {
                        return b.getValue() - a.getValue(); 
                    }
                    return b.getKey() - a.getKey(); 
                });

                sum = 0;
                int count = 0;
                for (Map.Entry<Integer, Integer> entry : entries) {
                    if (count < x) {
                        Integer key = entry.getKey();
                        Integer value = entry.getValue();
                        sum += key * value; 
                        count++;
                    } else {
                        break; 
                    }
                }
                ans[j - k + 1] = sum;
            }
            i++;
            j++;
        }
        return ans;
    }
}