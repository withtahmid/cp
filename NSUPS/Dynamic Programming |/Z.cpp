#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
const int N = 3e4 + 69, inf = 1e7;
int n, price, a[N], tot = 0, dp[N];
void solve(const int& tc){
    cin >> price >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < N; ++i){
        dp[i] = inf;
    }
    dp[0] = 0;
    for(int i = 0; i < n; ++i)for(int cent = N; cent >= 0; --cent){
        if(cent >= a[i]){
            dp[cent] = min(dp[cent - a[i]] + 1, dp[cent]);
        }
    }
    for(int i = price; i < N; ++i){
        if(dp[i] != inf){
            cout << i << ' ' << dp[i] << '\n';
            return;
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
