#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 7489 + 69;
int64_t dp[N][N];
const int coins[] = { 1, 5, 10, 25, 50 };
int64_t fn(int64_t left, int thcoin = 0){
    if(left <= 0 or thcoin == 5){
        return left == 0 ? 1 : 0;
    }
    int64_t& res = dp[left][thcoin];
    if(res != -1){
        return res;
    }
    res = fn(left, thcoin + 1);
    res += fn(left - coins[thcoin], thcoin);
    return res;
}
void solve(const int& tc){
    int64_t n;
    memset(dp, -1, sizeof(dp));
    while(cin >> n){
        cout << fn(n) << '\n'; 
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
