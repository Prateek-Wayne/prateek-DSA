class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();   
        int Left[n];
        //   
          Left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            // Left.push_back(max(Left[i-1],height[i]));  
            Left[i]=max(Left[i-1],height[i]);  
        }
          
          int Right[n];
        // vector<int> Right;
          Right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            Right[i]=max(Right[i+1],height[i]);
        }
        
        vector<int> Diff;
        for(int i=0;i<n;i++)
        {
            Diff.push_back(min(Right[i],Left[i]));
        }
        vector<int> Ans;
        for(int i=0;i<n;i++)
        {
            Ans.push_back(Diff[i]-height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=Ans[i];
        }
        return sum;
        
    }
};