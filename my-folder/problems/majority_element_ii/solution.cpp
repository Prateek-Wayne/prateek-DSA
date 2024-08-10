class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
    // if((n/3)<1)
    //     return arr;
    int first=INT_MIN;
    int second=INT_MAX;
    int fc=0;
    int sc=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==first && arr[i]!=second)
            fc++;
        else if(arr[i]==second && arr[i]!=first)
            sc++;
        else if(fc==0)
        {
            first=arr[i];
            fc++;
        }
        else if(sc==0)
        {
            second=arr[i];
            sc++;
        }
        else{
            fc--;
            sc--;
        }
    }
    fc=0;
    sc=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==first)
            fc++;
        else if(arr[i]==second)
            sc++;
    }
    vector<int> res;
    if(fc>n/3)
        res.push_back(first);
    if(sc>n/3)
        res.push_back(second);
    return res;
    
    cout<<first<<" | "<<second<<endl; 
    return res;
    }
};