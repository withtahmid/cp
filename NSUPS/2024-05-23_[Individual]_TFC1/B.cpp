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

const int N = 110;

int n, a[N], dp[N][N];

int fn(int l = 0, int r = n - 1){
    if(l == r){
        return 1;
    }
    
    int& res = dp[l][r];

    if(res != -1){
        return res;
    }

    if(a[l] == a[r]){
        return res = min(fn(l, r - 1), fn(l + 1, r));
    }

    res = (1 << 30);

    for(int i = l; i < r; ++i){
        res = min(res, fn(l, i) + fn(i + 1, r));
    }
    return res;
}

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << "Case " << tc << ": " << fn() << '\n';



}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
