class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int first=matrix[i][j];
                int second=matrix[j][i];
                matrix[i][j]=second;
                matrix[j][i]=first;
            }
        }
        int left=0;
        int end=n-1;
        while(left<end){
            for(int i=0;i<n;i++){
                int first=matrix[i][left];
                int second=matrix[i][end];
                matrix[i][left]=second;
                matrix[i][end]=first;
            }
            left++;
            end--;
        }
        return;
    
    }
}