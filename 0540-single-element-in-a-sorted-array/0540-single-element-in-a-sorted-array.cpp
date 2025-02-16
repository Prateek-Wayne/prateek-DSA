class Solution {
public:

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (arr.size() == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int left = 1, high = n - 2;
    while (left <= high)
    {
        int mid = left + (high - left) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];
        else if ((!(mid & 1) && arr[mid] == arr[mid - 1]) || ((mid & 1) && arr[mid] == arr[mid + 1]))
        {
            high = mid - 1;
        }
        else
            left = mid + 1;
    }
    return -1;
}
};