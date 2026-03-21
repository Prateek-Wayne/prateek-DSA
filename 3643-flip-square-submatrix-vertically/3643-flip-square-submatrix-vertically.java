class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int sr = x;
        int sc = y;
        int er = sr + k;
        int ec = y + k;
        // not possible to traverse...
        if (er > m || ec> n)
            return grid;
        for(int c=sc;c<ec;c++){
            int start=sr;
            int end=er-1;
            while(start<=end){
                int temp=grid[start][c];
                grid[start][c]=grid[end][c];
                grid[end][c]=temp;
                start++;
                end--;
            }
        }
        return grid;

    }
}