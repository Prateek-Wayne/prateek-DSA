class Solution {
    public boolean hasSameDigits(String s) {
        StringBuffer newString = new StringBuffer(s);
        while (newString.length() != 2) {
            StringBuffer temp = new StringBuffer();
            for (int i = 0; i < newString.length() - 1; i++) {
                int firstChar = newString.charAt(i) - '0';
                int secondChar = newString.charAt(i + 1) - '0';
                int newChar = (firstChar + secondChar) % 10;
                temp.append(newChar);
            }
            newString = temp;
        }
        if (newString.charAt(0) == newString.charAt(1))
            return true;
        return false;
    }
}