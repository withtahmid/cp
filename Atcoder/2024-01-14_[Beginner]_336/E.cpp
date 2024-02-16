/**
 *
 * Author: withtahmid
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
#define decimal(x) setprecision(x)
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
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(int);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
    return 0;
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod7 = (1e9 + 7);
const int mod9 = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}

const int maxsum = (9 * 14);
const int maxn = 15;
ll dp[maxn][maxsum][maxsum][2];

ll fn(const auto& s, int i, int sum, int mod, int small){
    if(i == len(s)){
        dbg(i, sum, mod);
        return (sum == 0) ? 1LL : 0LL;
    }
    auto& res = dp[i][sum][mod][small];
    if(res != -1LL){
        return res;
    }
    res = 0LL;
    if(small){
        for(int d = (i == 0 ? 1 : 0); d <= 9; ++d){
            res += fn(s, i + 1, (sum + d) % mod, mod, 1);
        }
    }else{
        for(int d = (i == 0 ? 1 : 0); d < int(s[i] - '0'); ++d){
            res += fn(s, i + 1, (sum + d) % mod, mod, 1);
        }
        int d = int(s[i] - '0');
        res += fn(s, i + 1, (sum + d) % mod, mod, 0);
    }
    return res;
}

void solve([[maybe_unused]] const int case_no){
    string s;
    read(s);
    memset(dp, -1LL, sizeof(dp));
    ll res = 0LL;
    // for(int i = 2; i <= maxsum; ++i){
    //     res += fn(s, 0, 0, i, 0);
    // }
    dbg(fn(s, 0, 0, 1, 0));
    
    println(res);

}
