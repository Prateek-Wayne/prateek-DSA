class Solution {
    public long sumAndMultiply(int n) {
        int newNum=0;
        long sum=0;
        int temp=n;
        while(temp!=0){
            int first=temp%10;
            temp/=10;
            if(first==0)
                continue;
            newNum=newNum*10+first;
            sum+=first;
        }
        long ans=0;
        while(newNum!=0){
            int first=newNum%10;
            newNum/=10;
            ans=ans*10+first;
        }
        return ans*sum;
    }
}