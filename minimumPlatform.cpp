#include <bits/stdc++.h>
using namespace std;

void findPlatform(int arr[], int dep[], int n)
{

    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=0;
        mp[dep[i]]=0;
    }

    for(int i=0;i<n;i++)
    {
        for(auto x:mp)
        {
            if(x.first>=arr[i] || x.first<=dep[i])
            {
                x.second++;
            }
        }
    }
    for(auto i:mp)
    {
        cout<<i.first<<"|"<<i.second<<endl;
    }
}

int main()
{
    int n = 6;
    int  arr[] = {900, 940, 950, 1100, 1500, 1800};
    int  dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    findPlatform(arr,dep,n);

}