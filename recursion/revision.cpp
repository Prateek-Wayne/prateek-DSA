#include<bits/stdc++.h>
using namespace std;

void rec(int i,int n)
{
    // base condition
    if(i==n+1)
        return ;
    //print
    cout<<i<<"|";
    rec(i+1,n);

}


int main()
{
    rec(1,10);
 return 0;
}