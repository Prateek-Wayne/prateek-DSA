// User function Template for Java

class Solution {

  static int search(String pat, String txt) {
        int i = 0;
        int j = 0;
        HashMap<Character, Integer> mp1 = new HashMap<>();
        HashMap<Character, Integer> mp2 = new HashMap<>();
        for (int k = 0; k < pat.length(); k++) {
            char x = pat.charAt(k);
            mp1.put(x, mp1.getOrDefault(x, 0) + 1);
        }
        int window = pat.length();
        int count = 0;
        while (j < txt.length()) {
            char charJ = txt.charAt(j);
            mp2.put(charJ, mp2.getOrDefault(charJ, 0) + 1);
            if (j - i + 1 < window) {

            } else if (j - i + 1 == window) {
                if (mp1.equals(mp2))
                    count++;
                char charI = txt.charAt(i);
                mp2.put(charI, mp2.get(charI) - 1);
                if (mp2.get(charI) == 0)
                    mp2.remove(charI);
                i++;
            }
            j++;
        }
        return count;

    }
}