#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 110;
int dp[N][N];

void lcs_table(string& a, string& b){
    int n = int(a.size()), m = int(b.size());
    for(int i = 0; i <= n; ++i)for(int j = 0; j <= m; ++j){
        if(i == 0 or j == 0){
            dp[i][j] = 0;
        }
        else if(a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
string lcs_str(string& a, string& b){
    lcs_table(a, b);
    int i = int(a.size()), j = int(b.size());
    string lcs = "";
    while( i > 0 and j > 0){
        if(a[i - 1] == b[j - 1]){
            lcs += a[i - 1], --i, --j;
        }else if(dp[i - 1][j] > dp[i][j - 1]){
            lcs += a[i - 1], --i;
        }else{
            lcs += b[j - 1], --j;
        }
    }
    
    /**/
        while(i > 0) lcs += a[i - 1], --i;
        while(j > 0) lcs += b[j - 1], --j;
    /**/
    
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

void solve(const int& tlcs_tablec){
    string a, b;
    while(cin >> a >> b){
        cout << lcs_str(a, b) << '\n';
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
