class Solution {
 public boolean checkOnesSegment(String s) {
        int segements = 0;
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                if (count > 0) {
                    segements++;
                }
                count = 0;
            } else {
                count++;
            }
        }
        if(count>0){
            segements++;
        }
        return (segements == 1);
    }
}