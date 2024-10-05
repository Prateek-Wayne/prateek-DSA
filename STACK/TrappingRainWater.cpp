#include<bits/stdc++.h>
using namespace std;

 int trap(vector<int>& height) {
        int n=height.size();
        //  MXR and MXL 
        int MXL[n];
        MXL[0]=height[0];
        for(int i=1;i<n;i++)
        {
            MXL[i]=max(MXL[i-1],height[i]);
        }
        int MXR[n];
        MXR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            MXR[i]=max(MXR[i+1],height[i]);
        }

        vector<int> diff;
        for(int i=0;i<n;i++)
            diff.push_back(min(MXR[i],MXL[i]));
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=(diff[i]-height[i]);
        }
        return ans;

        
    }


int main()
{

    return 0;


}