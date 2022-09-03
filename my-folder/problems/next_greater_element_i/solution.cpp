class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> v;
        int n=nums2.size()-1;
        for(int i=n;i>=0;i--)
        {
            if(s.size()==0)
                v.push_back(-1);
            else if(s.size()>0 && s.top()>nums2[i])
                v.push_back(s.top());
            else if(s.size()>0 && s.top()<=nums2[i])
            {
                while(s.size()>0 && s.top()<=nums2[i])
                    s.pop();
                if(s.size()==0)
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(v.begin(),v.end());
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]=v[i];
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            auto it=m.find(nums1[i]);
            ans.push_back(it->second);
        }
        return ans;
    }
};