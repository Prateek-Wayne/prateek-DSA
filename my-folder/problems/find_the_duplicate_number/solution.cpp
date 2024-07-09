class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        
        int N = arr.size();
    int i=0;
    while(i<N)
    {
        if(arr[i]!=arr[arr[i]-1])
        {
            swap(arr[i],arr[arr[i]-1]);
            // i++;
        }
        else if(arr[i]==arr[arr[i]-1])
            i++;
    }

    for(int i=0;i<N;i++)
    {
        if(arr[i]!=i+1)
            return arr[i];
    }
        return -1;
    }
};