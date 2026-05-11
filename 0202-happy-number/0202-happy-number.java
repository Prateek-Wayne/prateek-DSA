class Solution {
    public boolean isHappy(int n) {
        Set<Integer> st=new HashSet<>();
        while(true){
            int sum=0;
            while(n!=0){
                int lastDigit=n%10;
                n=n/10;
                sum+=(lastDigit*lastDigit);
            }
            n=sum;
            if(sum==1)
                return true;
            if(st.contains(n))
                return false;
            st.add(n);
        }
        // return false;
    }
}