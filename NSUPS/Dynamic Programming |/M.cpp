#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 1e4 + 69;

int64_t dp[N][2];
int n, arr[N];
int64_t fn(int i = 0, int prev = 0){
    if(i == n){
        return 0;
    }
    int64_t& res = dp[i][prev];
    if(res != -1){
        return res;
    }
    res = fn(i + 1, 0);
    if(prev == 0){
        res = max(res, fn(i + 1, 1) + arr[i]);
    }
    return res;
}
void solve(const int& tc){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Case "<< tc <<": " << fn() << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
    dbg(sqrt(1e5));
}
