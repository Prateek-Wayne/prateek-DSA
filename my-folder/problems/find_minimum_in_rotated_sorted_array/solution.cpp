class Solution {
public:
    int findMin(vector<int>& arr) {
        
         int start = 0;
    int end = arr.size() - 1;
    if (arr[start] <= arr[end])
        return arr[start];
int n=arr.size();
    while (start <= end)
    {

        int mid = start + (end - start) / 2;
        
        int prev = (mid +n- 1)%n;
        int next = (mid + 1)%n;
        if (arr[prev] >= arr[mid] && arr[next] >= arr[mid])
            return arr[mid];
        else if (arr[start] <= arr[end])
            return arr[start];
        else if (arr[start] <= arr[mid])
            start = mid + 1;
        else if (arr[mid] <= arr[end])
            end = mid - 1;
    }
    return 0;
    }
};