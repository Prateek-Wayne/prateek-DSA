#include<bits/stdc++.h>
using namespace std;

 int countGoodNumbers(long long n) {
        long long modd=1e9+7;
        long long  ans=1;
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
                ans = (ans * 5) % modd;
            else
                ans = (ans * 4) % modd;
        }
        return ans;
    }
int main()
{
    cout<<countGoodNumbers(50);
 return 0;
}