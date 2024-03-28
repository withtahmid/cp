#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
#define int int64_t


void solve(const int& tc){
    
    int a, b, m;

    cin >> a >> b >> m;
    
    auto upto = [&](int lim, int num) -> int{
        return lim / num;
    };

    int l = upto(m, a);
    int r = upto(m, b);
    
    cout << l + r  + 2 << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    dbg(__init__());
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
    dbg(__elapsed__());
}
