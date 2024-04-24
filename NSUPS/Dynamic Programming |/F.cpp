#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

void solve(const int& tc){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }
    int res  = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            auto t = v; 
            for(int k = i; k <= j; ++k){
                t[k] = 1 - t[k];
            }
            int cnt = 0;
            for(int k = 0; k < n; ++k){
                cnt += t[k];
            }
            res = max(res, cnt);
        }
    }
    cout << res << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
