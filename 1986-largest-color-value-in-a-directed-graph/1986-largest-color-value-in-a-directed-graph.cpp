const int N=100000;
vector<int> adj[N];
int q[N], front=0, back=0;// for queue
int freq[N][26];
class Solution {
public:
    static int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int n=colors.size();
        for(int i=0; i<n; i++)
            adj[i].clear();// reset
        vector<int> deg(n, 0);
        for (auto& e : edges) {
            const int u=e[0], v=e[1];
            adj[u].push_back(v);
            deg[v]++;
        }
    
        back=front=0;// reset for q
        for(int i=0; i<n; i++){
            memset(freq[i], 0, 26*sizeof(int));// reset for freq[i][26]={0}
            if (deg[i]==0){
                q[back++]=i;// push to q
                freq[i][colors[i]-'a']++;
            }
        }
        int ans=0, visited=0;
        while(front!=back){// q is not empty
            int u=q[front++]; // pop front
            int x=*max_element(freq[u], freq[u]+26);
            ans=max(ans, x);
            visited++;
            for(int v:adj[u]){
                for(int i=0; i<26; i++){
                    int uv=freq[u][i]+(i==colors[v]-'a');
                    freq[v][i]=max(freq[v][i], uv );
                }
                if (--deg[v]==0) q[back++]=v;// push to q
            }


        }
        return visited<n ? -1 : ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();