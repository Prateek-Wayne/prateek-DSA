#include <bits/stdc++.h>
using namespace std;

class Data{

    public:
    int value;
    int row;
    int col;
    Data(int v,int r,int c){
        value=v;
        row=r;
        col=c;
    }

};

// vector<int> mergeKArrays(vector<vector<int>> arr, int K)
void mergeKArrays(vector<vector<int>> arr, int K)
{
    
    priority_queue<Data, vector<Data> , greater<Data> > q;
    vector<int> ans;

    for(int i=0;i<K;i++)
    {
        Data data(arr[i][0],i,0);
        q.push(data);
    }
    while(!q.empty())
    {
        auto it=q.top();
        q.pop();
        ans.push_back(it.value);
        int r=it.row;
        int c=it.col+1;
        if(r < K && c < arr[r].size())
        {
            Data data(arr[r][c], r, c);
            q.push(data);
        }
    }
    for(auto i:ans)
        cout<<i<<"|";


}

int main()
{
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    mergeKArrays(arr,arr.size());
}