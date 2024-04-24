#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
const int N = 10;
int64_t dp[N][N];
void solve(const int& tc){
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for(int i = n - 1; i >= 0; --i)for(int j = m - 1; j >= 0; --j){
        if(i == n - 1 and j == m - 1){
            dp[i][j] = 1;
        }else{
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    cout << dp[0][0] << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
