class Solution {
public:
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    long long n = grid[0].size() * grid[0].size();
    long long totalSum = ((n) * (n + 1)) / 2;
    long long totalSqSum = ((n) * (n + 1) * (2 * n + 1)) / 6;
    long long actualSum = 0;
    long long actualSqSum = 0;
    for (int i = 0; i < grid[0].size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            actualSum += grid[i][j];
            actualSqSum += grid[i][j] * grid[i][j];
        }
    }
    // eq 1;
    // b-a
    long long eq1 = totalSum - actualSum;
    long long eq2 = (totalSqSum - actualSqSum) / eq1;
    int b = (eq1 + eq2) / 2;
    int a = (eq1 - eq2) / 2;
    return {abs(a), b};
}
};