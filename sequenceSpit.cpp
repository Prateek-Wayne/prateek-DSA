#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
void generateSubstrings(const string &s, int len, unordered_set<string> &substrings) {
    for (int i = 0; i <= s.size() - len; ++i) {
        substrings.insert(s.substr(i, len));
    }
}

string findMinimalString(const string &s) {
    unordered_set<string> substrings;
    for (int len = 1; ; ++len) {
        substrings.clear();
        generateSubstrings(s, len, substrings);
        string candidate(len, 'a');
        while (true) {
            if (substrings.find(candidate) == substrings.end()) {
                return candidate;
            }
            int pos = len - 1;
            while (pos >= 0 && candidate[pos] == 'z') {
                candidate[pos] = 'a';
                --pos;
            }
            if (pos < 0) break;
            ++candidate[pos];
        }
    }
}

int main() {
    string S;
    cin >> S;
    cout << findMinimalString(S) << endl;
    return 0;
}
