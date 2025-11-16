class Solution {
    public int diagonalSum(int[][] mat) {
        int sum=0;
        int n=mat[0].length;

        // left to right diagonal...
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
        }
        int l=n-1;
        while(l>=0){
            if(n-1-l==l)
                {
                    l--;continue;}
            sum+=mat[n-1-l][l];
            l--;
        }
        return sum;
    }
}