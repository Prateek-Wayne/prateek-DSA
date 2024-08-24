#include <bits/stdc++.h>
using namespace std;

void subarraySum(vector<int> &arr, int k){

    int ans=0;
    int curr_sum=0;
    int left=0;
    int right=0;
    while(right<arr.size())
    {
        curr_sum+=arr[right];
        cout<<"Current Sum for index :"<<right<<"|"<<curr_sum<<endl;
        if(curr_sum<k)
        {   
            right++;
        }
        else if(curr_sum==k)
        {
            ans+=1;
            right++;
        }
        else if(curr_sum>k)
        {   
            while(curr_sum>k)
            {
               
            curr_sum-=arr[left];
            left++;
             if(curr_sum==k)
                {
                    ans++;
                    right++;
                    break;
                }

            }
        }
    }
    cout<<"Count"<<ans;
}
int main(){
    vector<int> arr ={1};
    subarraySum(arr,0);

}