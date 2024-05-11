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
typedef long double ld;
typedef pair<int, int> pii;
#define int int64_t
const int N = 2e5 + 69, mod = 998244353;
int dig[12][N];

void solve(const int& case_no){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }
    memset(dig, 0, sizeof(dig));
    for(int i = 0; i < n; ++i){
        dig[len(to_string(v[i]))][i] = 1;
    }
    for(int i = 0; i < 11; ++i){
        for(int j = 1; j < n; ++j){
            dig[i][j] += dig[i][j - 1];
        }
    }
    vector<int>pf(n);
    pf[0] = v[0];
    for(int i = 1; i < n; ++i){
        pf[i] = pf[i - 1] + v[i];
    }
    int res = 0ll;
    for(int i = 0; i < n; ++i){
        int bigval = 0LL;
        bigval += (v[i] * 10 * dig[1][n - 1] - (i > 0 ? dig[1][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 100 * dig[2][n - 1] - (i > 0 ? dig[2][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 1000 * dig[3][n - 1] - (i > 0 ? dig[3][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 10000 * dig[4][n - 1] - (i > 0 ? dig[4][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 100000 * dig[5][n - 1] - (i > 0 ? dig[5][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 1000000 * dig[6][n - 1] - (i > 0 ? dig[6][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 1000000 * dig[7][n - 1] - (i > 0 ? dig[7][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 10000000 * dig[8][n - 1] - (i > 0 ? dig[8][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 100000000 * dig[9][n - 1] - (i > 0 ? dig[9][i -1] : 0));
        bigval %= mod;
        bigval += (v[i] * 1000000000 * dig[10][n - 1] - (i > 0 ? dig[10][i -1] : 0));
        bigval %= mod;
        bigval += pf.back() - (i > 0 ? pf[i - 1] : 0);
        bigval %= mod;
        res += bigval;
        res %= mod;
    }
    cout << res << '\n';
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
