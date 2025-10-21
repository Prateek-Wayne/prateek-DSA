class Solution {
 public static void helper(int[] candidates, int target, int index, List<Integer> ds, List<List<Integer>> ans) {
        if (index == candidates.length) {
            if (target == 0) {
                ans.add(new ArrayList<>(ds));
            }
            return;
        }
        if (target - candidates[index] >= 0) {
            ds.add(candidates[index]);

            helper(candidates, target - candidates[index], index, ds, ans);
            // undo
            ds.removeLast();
        }
        helper(candidates, target, index + 1, ds, ans);
    }

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> ds = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        helper(candidates, target, 0, ds, ans);
        return ans;
    }
}