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
    string s;
    read(n, s);
    int res = 0;
    for(int i = 0; i < n;){
        if((i + 4 < n) and s.substr(i, 5) == "mapie"){
            ++res;
            i += 5;
        }else if((i + 2 < n ) and (s.substr(i, 3) == "map" or s.substr(i, 3) == "pie")){
            i += 3;
            ++res;
        }else{
            ++i;
        }
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
