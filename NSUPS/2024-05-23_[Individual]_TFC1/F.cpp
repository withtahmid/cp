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

const int N = 110, K = 1e5 + 69, MOD = 1e9 + 7;

static int n, k, a[N], dp[K], pf[K];

void solve(const int& tc){
    
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    dp[0] = 1;

    for(int i = 0; i < n; ++i){
        
        for(int j = 0; j <= k; ++j){
            pf[j] = dp[j] + (j > 0 ? pf[j - 1] : 0);
        }

        for(int j = 0; j <= k; ++j){
            dp[j] = (pf[j] - (j - a[i] > 0 ? pf[j - a[i] - 1] : 0)) % MOD;
        }

    }

    cout << dp[k] << '\n';

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
