class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        long long i=0,j=0;
        double sum=0;
        double maxy=INT_MIN;
        int N=arr.size();
       while(j<N)
       {
            sum+=arr[j];
            if(j-i+1<k)
                    j++;
            else if(j-i+1==k)
            {
            
                maxy=max(maxy,sum);
                sum-=arr[i];
                j++;
                i++;
            }
    
       }    cout<<maxy<<" ";
          return maxy/k;
    }
};