/**
 *
 * Author: withtahmid
 * Created: 2024-03-11 20:32:39
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline bool read(auto &...x) { return (((cin >> x) ? 1 : 0) && ...); }
inline void print(const auto &...x) {((cout << x), ...); }
inline void println(const auto &...x) { print(x..., '\n'); }

void solve([[maybe_unused]] const int& case_no){
    int n, m, k;
    read(n, m, k);
    vector<int> b(n), c(m);
    for(auto& i : b){
        read(i);
    }
    for(auto& i : c){
        read(i);
    }
    sort(all(b));
    sort(all(c));
    ll res = 0ll;
    for(int i = 0; i < n; ++i){
        res += upper_bound(all(c), k - b[i]) - c.begin();
    }
    println(res);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(__case__(tc));
        solve(tc);
    }
    dbg(__elapsed__());
}
