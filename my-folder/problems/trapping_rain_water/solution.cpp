class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        //creating maxL
        int maxL[n];
        maxL[0]=height[0];
        for(int i=1;i<n;i++)
        {
            maxL[i]=max(maxL[i-1],height[i]);
        }
        //creating maxR
        int maxR[n];
        maxR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxR[i]=max(maxR[i+1],height[i]);
        }
        int weight[n];
        for(int i=0;i<n;i++)
        {
            weight[i]=min(maxL[i],maxR[i])-height[i];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=weight[i];
        }
        return sum;
    }
    
};