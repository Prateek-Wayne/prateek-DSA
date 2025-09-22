class Solution {
 public static String encode(String s[]) {
        // write your logic to encode the strings
        String encodedString = "";
        for (String i : s) {
            encodedString += i.length() + "#" + i;
        }
        return encodedString;
    }

public static String[] decode(String s) {
        List<String> decodedArray = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            int j = s.indexOf('#', i);
            // Parse the length from the substring up to the delimiter.
            int length = Integer.parseInt(s.substring(i, j));
            i = j + 1;
            String temp = s.substring(i, i + length);
            decodedArray.add(temp);
            i += length;
        }
        
        String[] newString = new String[decodedArray.size()];
        return decodedArray.toArray(newString);
    }


}