class Solution {
    public boolean canBeEqual(String s1, String s2) {
        char[] s1Even = new char[] { s1.charAt(0), s1.charAt(2) };
        char[] s2Even = new char[] { s2.charAt(0), s2.charAt(2) };
        Arrays.sort(s1Even);
        Arrays.sort(s2Even);
        if (!Arrays.equals(s1Even, s2Even))
            return false;
        char[] s1Odd = new char[] { s1.charAt(1), s1.charAt(3) };
        char[] s2Odd = new char[] { s2.charAt(1), s2.charAt(3) };
        Arrays.sort(s1Odd);
        Arrays.sort(s2Odd);
        if (!Arrays.equals(s1Odd, s2Odd))
            return false;
        return true;

    }
}