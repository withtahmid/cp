#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 6100 + 69;

int dp[N][N], n;
string s;

int fn(int i, int j){
    if(i >= j){
        return 0;
    }
    int& res = dp[i][j];
    if(res != -1){
        return res;
    }
    if(s[i] == s[j]){
        return res = fn(i + 1, j - 1);
    }
    else{
        res = min(fn(i + 1, j) + 1, fn(i, j - 1) + 1);
    }
    return res;
}

void solve(const int& tc){

    cin >> s;
    ::n = int(s.size());
    memset(dp, -1, sizeof(dp));
    cout << fn(0, n - 1) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
