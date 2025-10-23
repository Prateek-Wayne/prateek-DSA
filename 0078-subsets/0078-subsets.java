class Solution {
static void helper(int[] nums, List<Integer> ds, List<List<Integer>> ans, int index) {
        if (index == nums.length) {
            ans.add(new ArrayList<>(ds));
            return;
        }
        ds.add(nums[index]);
        helper(nums, ds, ans, index + 1);
        ds.removeLast();
        helper(nums, ds, ans, index + 1);
    }

    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        helper(nums, ds, ans, 0);
        return ans;

    }
}