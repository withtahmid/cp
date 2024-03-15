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
    int n;
    read(n);
    vector<int>v(n);
    for(auto& i : v){
        read(i);
    }
    for(int i = 1; i + 1 < n; ++i){
        if(v[i] and v[i + 1] == 0){
            return println("NO");
        }

        v[i] -= (v[i - 1] * 2);
        v[i + 1] -= v[i - 1];
        v[i - 1] = 0;
        if(v[i] < 0 or v[i + 1] < 0){
            return println("NO");
        }
    }
    for(auto& i : v) {
        if(i != 0){
            return println("NO");
        }
    }
    println("YES");
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
