#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 2e5 + 69;
vector<int>adj[N];
vector<bool>taken(N, false);
int res = 0;

void dfs(int u, int par = -1){
    for(int v : adj[u]){
        if(v != par){
            dfs(v, u);
        }
    }
    if(par != -1 and not taken[u] and not taken[par]){
        taken[u] = taken[par] = 1;
        ++res;
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
    dfs(1);
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
