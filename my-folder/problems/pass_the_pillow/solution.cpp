class Solution {
public:
    int passThePillow(int n, int time) {
          int start=1; 
        int inc=1; 
        while(time--){ 
             if(start==n){ 
                 inc=-1; 
             } 
             if(start==1){ 
                 inc=1; 
             } 
            start+=inc; 
        } 
        return start; 
    }
};