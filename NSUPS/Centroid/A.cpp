#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 2e5 + 69;
vector<int>adj[N];
vector<int>cnt(N);
int dfs(int u, int par = -1){
    int child = 1;
    for(int v : adj[u]){
        if(v != par){
            child += dfs(v, u);
        }
    }
    return cnt[u] = child;
}

void solve(const int& tc){
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i){
        int c;
        cin >> c;
        adj[c].emplace_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i){
        cout << (cnt[i] ? cnt[i] - 1 : 0)  << ' ';
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
