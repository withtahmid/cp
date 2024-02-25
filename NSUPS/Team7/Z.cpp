/**
 *
 * Author: withtahmid
 * Created: 23-02-2024 10:12:31
 *
 **/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define local(...) 
#define debug(...)
#define dbg(...)
#endif
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto& a){cout<<a;}
inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
inline void print(const auto &...a) {((print(a)), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto& x){return(cin >> x) ? true : false;}
inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
template <class T>inline T scan(){T t;read(t);return t;}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(const int& case_no);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}
const int maxn = 210;

inline int64_t modNeg(int64_t x, int64_t m){
    int r = x % m;
    if(r < 0) r += m;
    return r;
}

int64_t dp[2][22][12];
int64_t fn(const auto& v, const auto& d, const auto& m){
    const int n = len(v);
    memset(dp, 0, sizeof(dp));
    dp[n & 1][0][m] = 1;
    for(int i = n - 1; i >= 0; --i){
        for(int rem = 0; rem < d; ++rem){
            for(int take = 0; take <= m; ++take){
                dp[i & 1][rem][take] = dp[~ i & 1][rem][take];
                if(take < m){
                    dp[i & 1][rem][take] += dp[~ i & 1][modNeg(v[i] + rem, d)][take + 1];
                }
            }
        }
    }
    return dp[0][0][0];
}

void solve(const int& case_no){
    int n, q;
    read(n, q);
    vector<ll>v(n);
    read(v);
    println("Case ", case_no, ":");
    while(q--){
        int d, m;
        read(d, m);
        println(fn(v, d, m));
    }
}
