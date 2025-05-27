class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long num1=0,num2=0;
        for(int i=1;i<=n;i++){
            if(i%m){
                num1+=i;
            }
            else
                num2+=i;
        }
        return num1-num2;
    }
};