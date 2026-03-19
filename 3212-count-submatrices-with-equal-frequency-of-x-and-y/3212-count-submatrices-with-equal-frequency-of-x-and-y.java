class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
   public static int numberOfSubmatrices(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Pair[][] newGrid = new Pair[m][n];
        for (int i = 0; i < m; i++) {
            Pair sum = new Pair(0, 0);
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') {
                    sum.x++;
                } else if (grid[i][j] == 'Y')
                    sum.y++;
                newGrid[i][j] = new Pair(sum.x, sum.y);
            }
        }
        int count = 0;
        for (int c = 0; c < n; c++) {
            Pair sum = new Pair(0, 0);
            for (int r = 0; r < m; r++) {
                Pair currPair = newGrid[r][c];
                sum.x += currPair.x;
                sum.y += currPair.y;
                newGrid[r][c] = new Pair(sum.x, sum.y);
                if (newGrid[r][c].x == newGrid[r][c].y && (newGrid[r][c].x!=0 && newGrid[r][c].y!=0))
                    count++;
            }
        }
        return count;
    }
}