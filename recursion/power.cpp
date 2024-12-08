#include <bits/stdc++.h>
using namespace std;


 double helper(double x,int n)
 {
    if(n<0)
    {
        n=abs(n);
        x=1/x;
    }
    // base condition...
    if(n==0)
        return 1;
    if(n==1)
        return x;
    // recursion....
    if(n%2)
        return helper(x,n-1)*x;
    else{
        return helper(x*x,n/2);
    }
 }
double myPow(double x, int n)
{
    return helper(x,n);
    
}

int main()
{   
    cout<<myPow( 1.00000,
-2147483648);
    return 0;
}