#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

void solve(const int& tc){
    int cnt = 0;
    for(int i = 0; i < 21; ++i){
        string s;
        cin >> s;
        int z = count(all(s), '0');
        int o = count(all(s), '1');
        // cnt += ( o =< z ? 1 : 0); 
        dbg(z, o);
        // cnt += s.back() != '0';
        cnt += o;
        cnt -= z;
    }
    cout << cnt << '\n';
    // cout << "12\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
