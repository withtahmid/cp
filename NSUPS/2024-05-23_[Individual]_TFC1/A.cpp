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

const int N = 1e6 + 69;
const int MOD = 1e9 + 7;

int n, dp[N];

int fn(int x = ::n){
    if(x < 0) return 0;
    if(x == 0) return 1;
    
    int& res = dp[x];
    
    if(res != -1) return res;
    res = 0LL;
    for(int i = 1; i <= 6; ++i){
        res = (res + fn(x - i)) % MOD;
    }
    return res;
}

void solve(const int& tc){
      cin >> n;
      dbg(n);
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
