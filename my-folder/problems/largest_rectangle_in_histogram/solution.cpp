class Solution {
public:
    vector<int> NSR(vector<int> &arr)
{
        int n=arr.size();
  vector<int> Right;
  stack<pair<int, int>> S1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (S1.size() == 0)
      Right.push_back(n);

    else if (S1.size() > 0 && S1.top().first < arr[i])
      Right.push_back(S1.top().second);

    else if (S1.size() > 0 && S1.top().first >= arr[i])
    {
      while (S1.size() > 0 && S1.top().first >= arr[i])
      {
        S1.pop();
      }
      if (S1.size() == 0)
        Right.push_back(n);
      else
        Right.push_back(S1.top().second);
    }
    S1.push({arr[i], i});
  }
  reverse(Right.begin(), Right.end());
  return Right;
}
    
    vector<int> NSL(vector<int> &arr)
{ 
        int n=arr.size();
  vector<int> Left;
  stack<pair<int, int>> S2;
  for (int i = 0; i < n; i++)
  {
    if (S2.size() == 0)
      Left.push_back(-1);

    else if (S2.size() > 0 && S2.top().first < arr[i])
      Left.push_back(S2.top().second);

    else if (S2.size() > 0 && S2.top().first >= arr[i])
    {
      while (S2.size() > 0 && S2.top().first >= arr[i])
      {
        S2.pop();
      }
      if (S2.size() == 0)
        Left.push_back(-1);
      else
        Left.push_back(S2.top().second);
    }
    S2.push({arr[i], i});
  }
  //  reverse(Right.begin(),Right.end());
  return Left;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> Right=NSR(heights);
        vector<int> Left=NSL(heights);
        vector<int> Width;
        vector<int> area;
        for(int i=0;i<n;i++)
        {
         
            Width.push_back(Right[i]-Left[i]-1);
            area.push_back(Width[i]*heights[i]);
        }
        int ans=*max_element(area.begin(),area.end());
        return ans;
    }
};