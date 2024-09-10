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
    int n, m;
    cin >> n >> m;
    
    vector<string>grid(n);
    
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }

    int top = n, bottom = 1, y;
    
    for(int i = 0; i < n; ++i){
        if(count(all(grid[i]), '#') == 1){
            top = min(top, i + 1), bottom = max(bottom, i + 1), y = grid[i].find('#') + 1;
        }
    }

    cout << ((bottom - top ) / 2) + top << " " << y << '\n';
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
