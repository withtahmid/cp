#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

map<int64_t, int64_t>dp;

int64_t fn(int64_t n){
    if(n < 2){
        return n;
    }
    if(dp.find(n) != dp.end()){
        return dp[n];
    }
    int64_t res = fn(n / 2) + fn(n / 3) + fn(n / 4);
    return dp[n] = max(n, res);
}
void solve(const int& tc){
    int64_t n;
    while(cin >> n){
        // dp.clear();
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
    dbg("END");
}
