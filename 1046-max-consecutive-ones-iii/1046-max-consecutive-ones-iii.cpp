class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        queue<int> q;
        int temp = 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        int N = arr.size();
        while (j < N) {
            q.push(arr[j]);
            if (arr[j] == 0)
                temp++;

            while (temp > k) {
                if (q.front() == 0)
                    temp--;
                q.pop();
            }
            ans = max(static_cast<int>(q.size()), ans);
            j++;
        }
        return ans;
    }
};