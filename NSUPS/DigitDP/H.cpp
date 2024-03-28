#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

int m, d;

const int maxDigit = 22;
const int64_t mod = 1e9 + 7;
int64_t dp[maxDigit][2][2][2000 + 10];

int64_t fn(const string& L, const string& R, int pos, int LT, int RT, int num){
    if(pos == -1){
        return num % m == 0 ? 1 : 0;
    }
    int64_t& res = dp[pos][LT][RT][num];
    if(res != -1 and not LT and not RT){
        return res;
    }
    int k = R.length() - pos;
    res = 0;
    int lo = LT ? L[pos] - '0' : 0, hi = RT ? R[pos] - '0' : 9;
    for(int i = lo; i <= hi; ++i){
        if(~k&1 and i == d) continue;
        res += fn(L, R, pos - 1,  (LT&&(i==lo)),(RT&&(i==hi)), ((num * 10) + i) % m);
        res %= mod;
    }
    return res;
}

int64_t go(string L, string R){
    reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
    L = L  + string(R.length() - L.length(), '0');
    return fn(L, R, int(R.size()) - 1, 1, 1, 0);
}


void solve(const int& tc){
    string L, R;
    cin >> m >> d >> L >> R;
    cout << go(L, R) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    memset(dp, -1, sizeof(dp));
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
