class Pair {
    int pr, pc; // parent row and col
    int cr, cc; // current row and col
    Pair(int pr, int pc, int cr, int cc) {
        this.pr = pr;
        this.pc = pc;
        this.cr = cr;
        this.cc = cc;
    }
}

class Solution {
    public boolean containsCycle(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] vis = new int[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    if (find(i, j, m, n, grid, vis)) return true;
                }
            }
        }
        return false;
    }

    boolean find(int i, int j, int m, int n, char[][] grid, int[][] vis) {
        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(-1, -1, i, j));
        vis[i][j] = 1;

        while (!q.isEmpty()) {
            Pair temp = q.remove();
            int pr = temp.pr, pc = temp.pc;
            int cr = temp.cr, cc = temp.cc;
            
            for (int x = 0; x < 4; x++) {
                int nr = cr + dr[x];
                int nc = cc + dc[x];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == grid[cr][cc]) {
                    if (vis[nr][nc] == 1) {
                        if (pr != nr || pc != nc) return true; // cycle found
                    } else {
                        vis[nr][nc] = 1;
                        q.add(new Pair(cr, cc, nr, nc));
                    }
                }
            }
        }
        return false;
    }
}