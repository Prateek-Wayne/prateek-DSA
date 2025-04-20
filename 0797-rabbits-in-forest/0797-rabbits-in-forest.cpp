class Solution {
public:
    int numRabbits(vector<int>& answers) {

        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == 0)
                ans += 1;
            else {
                mp[answers[i]]++;
                if (mp[answers[i]] == answers[i] + 1) {
                    ans += answers[i] + 1;
                    mp.erase(answers[i]);
                }
            }
        }
        for (auto i : mp) {
            ans += i.first + 1;
        }
        return ans;
    }
};