#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

#define int int64_t


void solve(const int& tc){
    int a, b, c;
    cin >> a >> b >> c;

    int need = 3 - (b % 3);
    need = need == 3 ? 0 : need;
    dbg(tc, need, c);
    if(need > c){
        cout << "-1\n";
        return;
    }
    b += need;
    c -= need;
    cout << a + (b / 3) + (c / 3) + (c % 3 != 0) << '\n';
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
