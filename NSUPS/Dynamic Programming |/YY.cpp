#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 6100 + 69;

int dp[N][N];


void solve(const int& tc){

    string s;
    cin >> s;
    int n = int(s.size());

    for(int i = 0; i < n; ++i)for(int j = i + 1; j < n; ++j){
        dp[i][j] = (1 << 30);
    }

    for(int i = n - 1; i >= 0; --i)for(int j = i; j < n; ++j){
        if(s[i] == s[j]){
            dp[i][j] = dp[i + 1][j - 1];
        }else{
            dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
        }
    }

    cout << dp[0][n - 1] << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
