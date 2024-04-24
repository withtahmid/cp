#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 20000 + 69;
vector<pair<int, int>>v(N);
int dp[N][N];
int fn(int i, int space){
    if(i == -1){
        return 0;
    }
    int& res = dp[i][space];
    if(res != -1){
        return res;
    }
    res = fn(i - 1, space);
    if(space >= v[i].first){
        res = max(res, fn(i - 1, space - v[i].first) + v[i].second);
    }
    return res;
}

void solve(const int& tc){
    int s, n;
    cin >> s >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i].second >> v[i].first;
    }
    memset(dp, -1, sizeof(dp));
    cout << fn(n - 1, s) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
