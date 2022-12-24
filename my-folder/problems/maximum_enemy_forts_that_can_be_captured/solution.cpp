class Solution {
public:
  
    // int captureForts(vector<int>& arr) {
        
        
//         int i, j;
//         int x=1;
//         int y=-1;
//     // int min_dist = INT_MAX;
//         int max=INT_MIN;
//         int n=arr.size();
//     for (i = 0; i < n; i++) {
//         for (j = i + 1; j < n; j++) {
//             if ((x == arr[i] && y == arr[j]
//                  || y == arr[i] && x == arr[j])
//                 && max < abs(i - j)) {
//                 max = abs(i - j);
//             }
//         }
//     }
    
//     return max-1;
//     }
        //.................................
      int captureForts(vector<int>& forts) {
        int one1 =0;
        int one2 =0;
        int zero1 =0;
         int zero2 =0;
        int minus1 =0;
         int minus2 =0;
        for(int i=0;i<forts.size();i++){
            if(forts[i]==1) one1=1;
            else if(forts[i]==0 && one1==1) zero1++;
            else if(forts[i]==-1 && one1==1){
                one1 = 0;
                minus1 = max(minus1,zero1);
            }
            if(forts[i]==1 && zero1>0) zero1=0;
        }
         for(int i=forts.size()-1; i>=0;i--){
            if(forts[i]==1) one2=1;
            else if(forts[i]==0 && one2==1) zero2++;
            else if(forts[i]==-1 && one2==1){
                one2 = 0;
                minus2 = max(minus2,zero2);
            }
              if(forts[i]==1 && zero2>0) zero2=0;
        }
        return max(minus1,minus2);
        
    }
        
};