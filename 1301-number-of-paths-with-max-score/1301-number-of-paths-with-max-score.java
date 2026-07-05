class Solution {
    static final int MOD = 1_000_000_007;
    
    public int[] pathsWithMaxScore(List<String> board) {
        int n = board.size();
        int[][] score = new int[n][n];
        int[][] ways = new int[n][n];
        //Initialization
        for(int[] row : score) {
            Arrays.fill(row, -1);
        }
        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        int dir[][] = {{1, 0}, {0, 1}, {1, 1}};

        //bottom-up
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                //blocked
                if(board.get(i).charAt(j) == 'X') continue;

                if(i == n-1 && j == n-1) continue;

                int best = -1;
                for(int[] d: dir) {
                    int r = i + d[0];
                    int c = j + d[1];

                    if(r < n && c < n) {
                        best = Math.max(best, score[r][c]);
                    }
                }
                if(best == -1) continue;
                int cnt = 0;
                for (int[] d : dir) {
                    int r = i + d[0];
                    int c = j + d[1];

                    if (r < n && c < n && score[r][c] == best)
                        cnt = (cnt + ways[r][c]) % MOD;
                }

                char ch = board.get(i).charAt(j);
                int val = (ch == 'E' || ch == 'S') ? 0 : ch - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt;
            }
        }
        if (ways[0][0] == 0)
            return new int[]{0, 0};

        return new int[]{score[0][0], ways[0][0]};
    }
}