#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int breakPoint = -1;
    // findiing breakPoint....
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }
    cout << "breakpoint is " << nums[breakPoint] << endl;
    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    // findinf next greatest number.(we know after breakpoint array will be sorted already...)
    for (int i = n - 1; i > breakPoint; i--)
    {
        if (nums[i] > nums[breakPoint])
        {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    cout << "after swaping breakpoint is " << nums[breakPoint] << endl;
    // now reverse array from breakpoint to end...
    reverse(nums.begin() + breakPoint + 1, nums.end());
    return;
}
 int maximumDifference(vector<int>& nums) {
        int miny=nums[0];
        int diff=-1;
        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i]==miny)
                continue;
            diff=max(diff,nums[i]-miny);
            cout<<"Inside for loop "<<i<<": diff var:"<<diff<<"differnece:"<<nums[i]-miny<<endl;
            miny=min(miny,nums[i]);
        }
        return diff;
        
    }
int main()
{
    // vector<int> v = {2, 3, 1};
    // vector<int> v = {9,4,3,2};
    vector<int> v = {999,997,980,976,948,940,938,928,924,917,907,907,881,878,864,862,859,857,848,840,824,824,824,805,802,798,788,777,775,766,755,748,735,732,727,705,700,697,693,679,676,644,634,624,599,596,588,583,562,558,553,539,537,536,509,491,485,483,454,449,438,425,403,368,345,327,287,285,270,263,255,248,235,234,224,221,201,189,187,183,179,168,155,153,150,144,107,102,102,87,80,57,55,49,48,45,26,26,23,15};
    cout<<maximumDifference(v);
    // nextPermutation(v);
    // for (auto i : v)
    //     cout << i << " ";
}