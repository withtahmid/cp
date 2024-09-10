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
    
    int n;
    
    cin >> n;
    
    auto p = vector<vector<int>>(2, vector<int>(n + 1, 0));

    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        p[y][x] = 1;
    }
    
    int res = 0;

    for(int i = 0; i - 1 < n; ++i){
        if( 0 < i && i < n){
            res += p[0][i] && p[1][i - 1] && p[1][i + 1];
            res += p[1][i] && p[0][i - 1] && p[0][i + 1];
        }
        if(p[0][i] && p[1][i]){
            res += (n - 2);
        }
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
