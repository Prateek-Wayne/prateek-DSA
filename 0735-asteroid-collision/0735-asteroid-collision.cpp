class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ls;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                ls.push_back(asteroids[i]);
            } else {
                while (!ls.empty() && ls.back() > 0 && ls.back() < abs(asteroids[i]))
                    ls.pop_back();
                if (!ls.empty() && ls.back() == abs(asteroids[i]))
                    ls.pop_back();
                else if (ls.empty() || ls.back() < 0)
                    ls.push_back(asteroids[i]);
            }
        }
        return ls;
    }
};