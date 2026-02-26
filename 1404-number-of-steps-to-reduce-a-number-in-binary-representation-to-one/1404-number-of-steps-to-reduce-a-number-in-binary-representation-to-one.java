class Solution {
   public static StringBuilder addOne(StringBuilder s) {
        int i = s.length() - 1;

        while (i >= 0 && s.charAt(i) == '1') {
            s.setCharAt(i, '0');
            i--;
        }

        if (i >= 0) {
            s.setCharAt(i, '1');
        } else {
            s.insert(0, '1');
        }

        return s;
    }

    public static int numSteps(String s) {
        StringBuilder newS = new StringBuilder(s);
        int count = 0;
        while (newS.length() != 1) {
            count++;
            int length = newS.length();
            if (newS.charAt(length - 1) == '0') {
                newS.deleteCharAt(length - 1);
            } else {
                newS = addOne(newS);
            }
        }
        return count;

    }
}