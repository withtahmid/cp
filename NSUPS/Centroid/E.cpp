#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 2e5 + 69;

vector<int>adj[N];

int64_t subsz[N], res[N];

int n;

void dfs(int u, int par, int depth = 0){
    res[1] += depth;
    subsz[u] = 1;
    for(int v : adj[u]){
        if(v != par){
            dfs(v, u, depth + 1);
            subsz[u] += subsz[v];
        }
    }
}


void dfs2(int u, int par){
    for(int v : adj[u]){
        if(v != par){
            res[v] = res[u] + n - 2LL * subsz[v];
            dfs2(v, u);
        }
    }
}

void solve(const int& tc){
    
    cin >> n;
    dbg(n);
    for(int i = 0; i + 1 < n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    
    dfs(1, -1), dfs2(1, -1);

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }

}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
