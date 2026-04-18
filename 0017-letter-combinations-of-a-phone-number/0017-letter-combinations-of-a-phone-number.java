class Solution {
    void helper(String s, int index, StringBuilder ds, Map<Character, String> mp, List<String> ans) {
        if (index == s.length()) {
            ans.add(new String(ds.toString()));
            return;
        }

        String keyPadString = mp.get(s.charAt(index));
        for (int i = 0; i < keyPadString.length(); i++) {
            ds.append(keyPadString.charAt(i));
            helper(s, index + 1, ds, mp, ans);
            ds.deleteCharAt(ds.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {

        Map<Character, String> mp = new HashMap<>();
        mp.put('2', "abc");
        mp.put('3', "def");
        mp.put('4', "ghi");
        mp.put('5', "jkl");
        mp.put('6', "mno");
        mp.put('7', "pqrs");
        mp.put('8', "tuv");
        mp.put('9', "wxyz");

        List<String> ans = new ArrayList<>();
        StringBuilder ds = new StringBuilder();

        helper(digits, 0, ds, mp, ans);
        return ans;
    }
}