class Solution {
static void helper(int[] nums, int index, List<Integer> ds, List<List<Integer>> ans) {
        if (index == nums.length) {
            ans.add(new ArrayList<>(ds));
            return;
        }
        // pick
        ds.add(nums[index]);
        helper(nums, index + 1, ds, ans);
        ds.removeLast();
        helper(nums, index + 1, ds, ans);
    }

    public static List<List<Integer>> subsets(int[] nums) {
        List<Integer> ds = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        helper(nums, 0, ds, ans);
        return ans;
    }
}