class Solution {

    public int minOperations(String s) {

        int withZero = 0;
        int withOne = 0;
        for (int i = 0; i < s.length(); i++) {
            // even index...
            if (i % 2 == 0) {
                if (s.charAt(i) != '0')
                    withZero++;
                if (s.charAt(i) != '1')
                    withOne++;
            } else {
                if (s.charAt(i) != '1')
                    withZero++;
                if (s.charAt(i) != '0')
                    withOne++;
            }
        }
        return Math.min(withZero, withOne);
    }
}