#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 2000 + 69;
int dp[N][N];
string a, b;
int fn(int i = ::a.length(), int j = ::b.length()){
    if(i == 0 or j == 0){
        return abs(i - j);
    }
    int& res = dp[i][j];
    if(res != -1){
        return res;
    }
    res = fn(i - 1, j - 1);
    if(a[i - 1] == b[j - 1]){
        return res;
    }else{
        res = min(res, fn(i - 1, j));
        res = min(res, fn(i, j - 1));
    }
    return ++res;
}
void solve(const int& tc){
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << fn() << '\n';
}



int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
