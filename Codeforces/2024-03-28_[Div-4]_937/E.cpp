/**
 *
 * Author: withtahmid
 * Created: 2024-03-28 20:43:17
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
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline bool read(auto &...x) { return (((cin >> x) ? 1 : 0) && ...); }
inline void read(vector<auto>& v){for(auto&i:v){cin>>i;}}
inline void print(const auto &...x) {((cout << x), ...); }
inline void println(const auto &...x) { print(x..., '\n'); }
void solve(const int& case_no){
    
    int n;
    string s;
    read(n, s);

    auto check = [&](int d)->bool{
        auto f1 = s.substr(0, d), f2 = s.substr(n - d, d);
        string s1, s2;
        while(len(s1) < n) s1 += f1, s2 += f2;
        int cnt1 = 0, cnt2  = 0;
        for(int i = 0; i < n; ++i) cnt1 += s[i] != s1[i], cnt2 += s[i] != s2[i];
        return cnt1 < 2 or cnt2 < 2;
    };

    int res = n;
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            if(check(i)) res = min(res , i);
            if(check(n / i))res = min(n / i, res);
        }   
    }
    println(res);
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    dbg(__init__());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(__case__(tc));
        solve(tc);
    }
    dbg(__elapsed__());
}
