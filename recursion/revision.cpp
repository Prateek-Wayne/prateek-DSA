#include<bits/stdc++.h>
using namespace std;


 int nthFibonacci(int n) {
        // code here
        if(n==0||n==1)
            return n;
        return nthFibonacci(n-1)+nthFibonacci(n-2);
    }

int main()
{
    cout<<nthFibonacci(1);

 return 0;
}