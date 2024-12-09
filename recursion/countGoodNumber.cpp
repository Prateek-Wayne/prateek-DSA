#include<bits/stdc++.h>
using namespace std;

static long long MOD=1e9+7;
long long helper(long long x,long long n)
{  
    // bases
    if(n==0)
        return 1;
    if(n==1)
        return x;

    if(n%2!=0)
        return (helper(x, n/2) * helper(x, n/2) % MOD * x) % MOD;
    else
        return (helper(x, n/2) * helper(x, n/2)) % MOD;

}

int countGoodNumbers(long long n) {

    long long even=helper(5,(n+1)/2)%MOD;
    long long odd=helper(4,n/2)%MOD;
    return int((even*odd)%MOD);

    }


int main()
{
    cout<<countGoodNumbers(1096);
 return 0;
}