#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int maxDigit = 42;
const int N = (1 << 5) + 2; 
const int mod = 1000007;
int64_t dp[maxDigit][N][1][2][3][4][5];

int64_t fn(int pos,  int mask, int r2, int r3, int r4, int r5, int r6){
    if(pos == -1){
        vector<int> vec = { r2, r3, r4, r5, r6 };
        for(int i = 0; i < 5; ++i){
            if((mask >> (i)) & 1 and vec[i] != 0){
                return 0;
            }
        }
        return 1;
    }
    int64_t& res = dp[pos][mask][r2][r3][r4][r5][r6];
    if(res != -1){
        return res;
    }
    res = 0;
    for(int i = 1; i <= 6; ++i){
        auto f = [i](int c, int m){
            return ((c * 10) + i) % m;
        };
        res += fn(pos - 1, i != 1 ? mask | (1 << (i - 2)) : mask, f(r2, 2), f(r3, 3), f(r4, 4), f(r5, 5), f(r6, 6));
        res %= mod;
    }
    return res;
}


void solve(const int& tc){
    int n;
    cin >> n;
    cout << fn(n - 1, 0, 0, 0, 0, 0, 0) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,-1, sizeof(dp));
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
