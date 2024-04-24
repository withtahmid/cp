#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 1000 + 69;
int dp[N][N];

int lcs_table(string& a, string& b){
    int n = int(a.size()), m = int(b.size());
    for(int i = 0; i <= n; ++i)for(int j = 0; j <= m; ++j){
        if(i == 0 or j == 0){
            dp[i][j] = 0;
        }else if(a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

void solve(const int& tc){
    string a, b;
    while(getline(cin, a) and getline(cin, b)){
        cout << lcs_table(a, b) << '\n';
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
