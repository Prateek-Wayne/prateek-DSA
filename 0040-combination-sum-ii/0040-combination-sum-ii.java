class Solution {
    void helper(int[] candidates, int target, int index, List<Integer> ds, List<List<Integer>> answer) {
        if (target == 0) {
            answer.add(new ArrayList<>(ds));
            return;
        }
        if (index == candidates.length || target < 0)
            return;
        ds.add(candidates[index]);
        helper(candidates, target - candidates[index], index + 1, ds, answer);
        ds.removeLast();
        int nextIndex = index + 1;
        while (nextIndex < candidates.length && candidates[nextIndex] == candidates[nextIndex - 1])
            nextIndex++;
        helper(candidates, target, nextIndex, ds, answer);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> answer = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        helper(candidates, target, 0, ds, answer);

        return answer;
    }
}