//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:

bool movement(vector<vector<int>> &visited, int i, int j)
{
    int n = visited.size();
    if ((i >= 0 && j >= 0) && (i < n && j < n) && (visited[i][j] == -1))
        return true;
    return false;
}

void helper(vector<vector<int>> &mat, int i, int j, string ds, vector<string> &ans, vector<vector<int>> &visited)
{
    int n = mat.size();
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(ds);
        return;
    }
    // up
    if (movement(visited, i - 1, j) && mat[i - 1][j] == 1)
    {
        visited[i][j] = 1;
        ds.push_back('U');
        helper(mat, i - 1, j, ds, ans, visited);
        ds.pop_back();
        visited[i][j] = -1;
    }
    // Down
    if (movement(visited, i + 1, j) && mat[i + 1][j] == 1)
    {
        visited[i][j] = 1;
        ds.push_back('D');
        helper(mat, i + 1, j, ds, ans, visited);
        ds.pop_back();
        visited[i][j] = -1;
    }
    // L
    if (movement(visited, i, j - 1) && mat[i][j - 1] == 1)
    {
        visited[i][j] = 1;
        ds.push_back('L');
        helper(mat, i, j - 1, ds, ans, visited);
        ds.pop_back();
        visited[i][j] = -1;
    }
    // "R"
    if (movement(visited, i, j + 1) && mat[i][j + 1] == 1)
    {
        visited[i][j] = 1;
        ds.push_back('R');
        helper(mat, i, j + 1, ds, ans, visited);
        ds.pop_back();
        visited[i][j] = -1;
    }

    return;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    // code here
    vector<string> ans;
    int n = mat.size();
    vector<vector<int>> visited(n, vector<int>(n, -1));
    helper(mat, 0, 0, "", ans, visited);
    return ans;
}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends