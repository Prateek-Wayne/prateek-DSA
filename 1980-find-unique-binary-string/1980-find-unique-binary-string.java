class Solution {
static void helper(int n, StringBuffer ds, List<String> ans) {
        if (n == 0) {
            ans.add(ds.toString());
            return;
        }
        // add 0...
        ds.append('0');
        helper(n - 1, ds, ans);
        ds.deleteCharAt(ds.length() - 1);
        ds.append('1');
        helper(n - 1, ds, ans);
        ds.deleteCharAt(ds.length() - 1);
    }

    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        List<String> ans = new ArrayList<>();
        StringBuffer ds = new StringBuffer("");
        helper(n, ds, ans);
        Map<String, Integer> mp = new HashMap<>();
        for (String i : ans) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        StringBuffer s;

        for (String keys : mp.keySet()) {
            if (mp.get(keys) == 1) {
                return keys;
            }
        }
        return "";
    }
}