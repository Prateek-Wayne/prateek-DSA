class Solution {

   List<Integer> helper(int num) {
        List<Integer> ans = new ArrayList<>();
        while (num > 0) {
            int last = num % 10;
            ans.add(last);
            num = num / 10;
        }
        return ans.reversed();
    }

    public int[] separateDigits(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i : nums) {
            List<Integer> seperatedNums = helper(i);
            ans.addAll(seperatedNums);
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}