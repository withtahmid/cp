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

map<int, vector<pii>> divisors;
vector<pii> divs(int n){
    if(divisors.find(n) != divisors.end()){
        return divisors[n];
    }
    vector<pii>v;
    for(int i = 2; i * i <= n; ++i){
        if(n % i != 0) continue;
        v.push_back({i, n / i});
    }
    
    return divisors[n] = v;
}
bool valid(const int &n){
    auto s = to_string(n);
    for(auto c : s){
        if(c != '0' and c != '1'){
            return false;
        }
    }
    return true;
}

int dp[100000 + 10];

int fn(int n){
    if(n < 2) return 1;
    if(dp[n] != -1){
        return dp[n];
    }
    if(valid(n)){
        return dp[n] = 1;
    }
    bool res = false;
    auto f = divs(n);
    for(auto i : f){
        res |= fn(i.first) and fn(i.second);
    }
    return dp[n] = res ? 1 : 0;
}


void solve(const int& case_no){
    int n;
    cin >> n;
    println(fn(n) ? "YES" : "NO");
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    dbg(__init__());
    memset(dp, -1, sizeof(dp));
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(__case__(tc));
        solve(tc);
    }
    dbg(__elapsed__());
}
