class Solution {
public String minWindow(String s, String t) {

    if (s.length() < t.length()) return "";

    HashMap<Character, Integer> need = new HashMap<>();
    for (char c : t.toCharArray()) {
        need.put(c, need.getOrDefault(c, 0) + 1);
    }

    HashMap<Character, Integer> window = new HashMap<>();

    int required = need.size();
    int formed = 0;

    int l = 0, r = 0;

    int minLen = Integer.MAX_VALUE;
    int start = 0;

    while (r < s.length()) {
        char c = s.charAt(r);
        window.put(c, window.getOrDefault(c, 0) + 1);

        if (need.containsKey(c) &&
            window.get(c).intValue() == need.get(c).intValue()) {
            formed++;
        }

        // shrink
        while (l <= r && formed == required) {

            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            char leftChar = s.charAt(l);
            window.put(leftChar, window.get(leftChar) - 1);

            if (need.containsKey(leftChar) &&
                window.get(leftChar) < need.get(leftChar)) {
                formed--;
            }

            l++;
        }

        r++;
    }

    return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
}
}