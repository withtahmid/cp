#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

void solve(const int& tc){
    int x, y;
    cin >> x >> y;

    auto t = (y / 2) + (y & 1);

    auto e = (7 * t) + ((y  & 1) ? 4 : 0);

    if(x <= e){
        cout << t << '\n';
    }else{
        x -= e;
        cout << t + ((x / 15) + (x % 15 != 0)) << '\n';
    }
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
