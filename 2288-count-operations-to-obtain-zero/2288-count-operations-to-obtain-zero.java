class Solution {
  public int countOperations(int num1, int num2) {
        int count = 0;
        while ( num1!=0 && num2!=0) {
            int sub = Math.abs(num1 - num2);
            if (num1 > num2) {
                num1 = sub;
                count++;
            } else {
                num2 = sub;
                count++;
            }
        }
        // if (num1 == 0 || num2 == 0)
        //     return count;
        return count ;
    }
}