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
typedef vector<int> vi;
inline bool read(auto &...x) { return (((cin >> x) ? 1 : 0) && ...); }
inline void read(vector<auto>& v){for(auto&i:v){cin>>i;}}
inline void print(const auto &...x) {((cout << x), ...); }
inline void println(const auto &...x) { print(x..., '\n'); }

void solve(const int& case_no){
    
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    dbg(__init__());
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(__case__(tc));
        solve(tc);
    }
    dbg(__elapsed__());
}
