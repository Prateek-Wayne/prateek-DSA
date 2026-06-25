class Solution {
 public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> st = new HashSet<>();
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            int target = -nums[i];
            HashMap<Integer, Integer> mp = new HashMap<>();
            mp.put(nums[i + 1], i);
            for (int j = i + 2; j < n; j++) {
                int req = target - nums[j];
                if (mp.get(req) != null) {
                    List<Integer> ds = new ArrayList<>(List.of(nums[i], nums[j], req));
                    ds.sort(null);
                    st.add(ds);
                }
                mp.put(nums[j], j);
            }
        }
        return st.stream().toList();
    }
}