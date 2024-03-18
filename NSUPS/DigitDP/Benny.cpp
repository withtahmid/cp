#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
int dp[10][2][2];
int fn(const string& s, int pos = 0, int tight = 1, int has = 0){
    if(pos == int(s.size())){
        return has ? 1 : 0;
    }
    int& res = dp[pos][tight][has];
    if(res != -1){
        return res;
    }
    res = 0;
    if(tight){
        for(int i = 0; i < s[pos] - '0'; ++i){
            res += fn(s, pos + 1, 0, (i == 3) or has);
        }
        res += fn(s, pos + 1, 1);
    }else{
        for(int i = 0; i <= 9; ++i){
            res += fn(s, pos + 1, 0, (i == 3) or has);
        }
    }
    return res;
}
void solve(const int& tc){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    cout << n - fn(s) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
