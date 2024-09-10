#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

void solve(const int& tc){
    int64_t x, y, k;
    cin >> x >> y >> k;
    cout << max((2 * (( x + k - 1) / k)) - 1, 2 * ((y + k - 1) / k)) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
