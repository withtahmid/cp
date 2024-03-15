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
    int n, m, x;
    read(n, m, x);

    auto cl = [&](int i, int d)-> int{
        int pos = (i + d) % n;
        pos = (pos == 0 ? n : pos);
        return pos;
    };

    auto ccl = [&](int i, int d) -> int{
        d %= n;
        int pos = (i + (n - d)) % n;
        pos = (pos == 0 ? n : pos);
        return pos;
    };

    vector<int>pos = { x };
    for(int i = 0; i < m; ++i){
        int d;
        char mode;
        read(d, mode);
        set<int>next;
        while(len(pos)){
            if(mode == '?'){
                next.insert(cl(pos.back(), d));
                next.insert(ccl(pos.back(), d));
            }else if(mode == '0'){
                next.insert(cl(pos.back(), d));
            }else{
                 next.insert(ccl(pos.back(), d));
            }
            pos.pop_back();
        }
        pos = vector<int>(all(next));
    }
    auto res = set<int>(all(pos));
    println(len(res));
    for(auto& i : res){
        print(i, " ");
    }
    println();
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
