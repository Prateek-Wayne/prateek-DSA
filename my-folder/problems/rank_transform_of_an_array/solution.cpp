class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         vector<int> t=arr;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        int rank = 1; // initialize rank to 1
        for(int i=0;i<n;i++)
        {   
            if(i == 0 || arr[i] != arr[i-1]) // if this is the first element or a new element
            {
                mp[arr[i]]=rank; // assign the current rank
                rank++; // increment the rank
            }
            // no need to handle the case when arr[i] == arr[i-1], because we want to give them the same rank
        }
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(mp[t[i]]);   
        }
        return v;
    }
};