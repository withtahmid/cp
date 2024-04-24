#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 1e5 + 69;
int dp[N], a[N], n;
void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] >= a[i - 1]){
            dp[i] = dp[i - 1] + 1; 
        }else{
            dp[i] = 1;
        }
    }
    cout << *max_element(dp, dp + n) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
