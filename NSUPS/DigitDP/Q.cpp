#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif


const int maxDigit = 11;
int dp[maxDigit][2][2][100];

int k;

int fn(const string& L, const string& R, int pos, int LT, int RT, int sum = 0, int rem = 0){
    if(pos == -1){
        return rem == 0 and sum % k == 0 ? 1 : 0;
    }
    int& res = dp[pos][LT][RT][sum];
    if(res != -1 and not LT and not RT){
        return res;
    }
    res = 0;
    int lo = LT ? L[pos] - '0' : 0, hi = RT ? R[pos] - '0' : 9;
    for(int i = lo; i <= hi; ++i){
        res += fn(L, R, pos - 1,  (LT&&(i==lo)),(RT&&(i==hi)), sum + i, ((rem * 10) + i) % k);
    }
    return res;
}

int go(string L, string R){
    reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
    L = L  + string(R.length() - L.length(), '0');
    return fn(L, R, int(R.size()) - 1, 1, 1);
}


void solve(const int& tc){
    string L, R;
    cin >> L >> R >> k;
    dbg(L, R);
    memset(dp,-1, sizeof(dp));
    cout << "Case " << tc << ": " << go(L, R) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
