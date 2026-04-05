class Solution {
    public boolean judgeCircle(String moves) {

        int countUp = 0;
        int countRight = 0;
        for (int i = 0; i < moves.length(); i++) {
            Character c = moves.charAt(i);
            if (c == 'U')
                countUp++;
            else if (c == 'D')
                countUp--;
            else if (c == 'R')
                countRight++;
            else if (c == 'L')
                countRight--;
        }
        return countRight == 0 && countUp == 0;
    }
}