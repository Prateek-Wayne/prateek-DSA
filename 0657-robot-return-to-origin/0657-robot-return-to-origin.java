class Solution {
    public boolean judgeCircle(String moves) {

        int x = 0;
        int y = 0;
        for (int i = 0; i < moves.length(); i++) {
            Character c = moves.charAt(i);
            switch (c) {
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'L':
                    x--;
                    break;
            }
        }
        return x == 0 && y == 0;

    }
}