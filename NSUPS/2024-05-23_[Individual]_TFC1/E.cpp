#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

const int N = 21;

vector<int>adj[N];
int n, m, dp[N][(1 << N)];
int64_t fn(int on = 1, int visited = 1){
    if(on == n){
        return (visited == ((1 << n) - 1)) ? 1 : 0;
    }
    int64_t& res = dp[on][visited];
    if(res != -1) return res;
    res = 0;
    for(auto i : adj[on]){
        if((visited >> (i - 1))&1) continue;
        res += fn(i, (visited | (1 << (i - 1))));
        res %= int(1e9 + 7);
    }
    return res;
}
void solve(const int& tc){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    memset(dp, -1, sizeof(dp));
    cout << fn() << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
