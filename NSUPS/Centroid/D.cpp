#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 2e5 + 69;

vector<int>adj[N];

void bfs(auto& dist, int src){
    // dist.resize(adj.size());
    // fill(dist.begin(), dist.end(), -1);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    while(not q.empty()){
        auto u = q.front();
        q.pop();
        for(auto i : adj[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
}
void solve(const int& tc){
    int n;
    cin >> n;
    for(int i = 0; i + 1 < n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    vector<int>dist = vector<int>(n + 1, -1);
    bfs(dist, 1);
    int mxdst = 0, fnode = 1;
    for(int i = 1; i <= n; ++i){
        if(dist[i] > mxdst){
            mxdst = dist[i], fnode = i;
        }
    }

    int left_diameter = fnode;

    dist = vector<int>(n + 1, -1);

    bfs(dist, left_diameter);
    
    int right_diameter = fnode;
    mxdst = 0;
    
    for(int i = 1; i <= n; ++i){
        if(dist[i] > mxdst){
            mxdst = dist[i], right_diameter = i;
        }
    }
    
    vector<int>dist2(N + 1, -1);
    bfs(dist2, right_diameter);
    
    for(int i = 1; i <= n; ++i){
        cout << max(dist[i], dist2[i]) << ' ';
    }
    cout << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
