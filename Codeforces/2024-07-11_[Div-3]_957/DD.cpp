#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 69;
int64_t n, m, k;
string s;
int64_t dp[N];
int64_t fn(int i){
    if(i == -1){
        int64_t res = 1LL << 31;
        for(int j = 1; j <= m; ++j) res = min(res, fn(i + j));
        return res;
    }
    if(i >= s.length()) {
        return 0;
    }
    if(s[i] == 'C') {
        return 1LL << 31;
    }
    int64_t& res = dp[i];
    if(res != -1) {
        return res;
    }
    if(s[i] == 'W') {
        return res = fn(i + 1) + 1;
    }
    res = 1LL << 31;
    for(int j = 1; j <= m; ++j) {
        res = min(res, fn(i + j));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> s;
        for(int i = 0; i < n + 5; ++i) dp[i] = -1;
        cout << (fn(-1) > k ? "NO" : "YES") << '\n';
    }
}