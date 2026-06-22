class Solution {
    public int maxNumberOfBalloons(String text) {
        HashMap<Character, Integer> mp = new HashMap<>();
        String b = "balloon";
        for (int i = 0; i < b.length(); i++) {
            Character c = b.charAt(i);
            mp.put(c, 0);
        }
        for (int i = 0; i < text.length(); i++) {
            Character c = text.charAt(i);
            if (b.contains(c.toString())) {
                mp.put(c, mp.get(c) + 1);
            }
        }
        Integer mini = text.length();
        for (Character k : mp.keySet()) {
            if (k == 'o' || k == 'l') {
                mp.put(k, mp.get(k) / 2);
            }
            mini = Math.min(mp.get(k), mini);
        }
        return mini;
    }
}