#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
int dp[11][11];
int fn(const int& n, const vector<int>& s, int pos = 0, int prev = 0){
    if(pos == n){
        return 1;
    }
    int& res = dp[pos][prev];
    if(res != -1){
        return res;
    }
    res = 0;
    for(int i = 0; i < int(s.size()); ++i){
        if(abs(prev - s[i]) <= 2 or prev == 0){
            res += fn(n, s, pos + 1, s[i]);
        }
    }
    return res;
}
void solve(const int& tc){
    int m, n;
    cin >> m >> n;
    vector<int>s(m);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < m; ++i){
        cin >> s[i];
    }
    cout << "Case " << tc <<": " << fn(n, s) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
