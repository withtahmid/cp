#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

void solve(const int& tc){
    int a, b;
    cin >> a >> b;
    int res = INT_MAX;
    for(int c = a; c <= b; ++c){
        res = min(res, (c - a) + (b - c));
    }
    cout << res << "\n";
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
