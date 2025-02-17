class Solution {
public:


pair<int, int> minMax(vector<int> &arr)
{
    int mini = INT_MAX, maxy = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < mini)
            mini = min(mini, arr[i]);
        if (arr[i] > maxy)
            maxy = max(maxy, arr[i]);
    }
    return {mini, maxy};
}

double calculateHours(vector<int> &piles, int x)
{
    double hours = 0;
    for (double i = 0; i < double(piles.size()); i++)
    {
        hours += ceil(double(piles[i]) / double(x));
    }
    return hours;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    auto i = minMax(piles);
    int low = 1;
    int high = i.second;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        double totalHours = calculateHours(piles, mid);
        if (totalHours <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
};