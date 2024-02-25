/**
 *
 * Author: withtahmid
 * Created: 24-02-2024 16:09:37
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
inline string kes(int k){return("Case "+to_string(k)+": ");}
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
    bool test_case = not true;
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
const int maxn = (365 * 80) + 69;
ll dp[maxn];
ll fn(int i, const auto& v){
    if(i <= 0){
        return 0LL;
    }
    auto& res = dp[i];
    if(res != -1LL){
        return res;
    }
    res = OO;
    for(ll x = 1; x <= 7; ++x){
        if(i - x < 0) break;
        res = min(res, fn(i - x, v) + (x * v[i - x]));
    }
    // dbg(i, res);
    return res;
}

void solve(const int& case_no){
    int n;
    read(n);
    vector<ll>v(n);
    read(v);
    memset(dp, -1LL , sizeof(dp));
    println(fn(n , v));
    for(int i = 0; i < n; ++i){
        ll mn = oo;
        for(int j = 0; j < 7; ++j){
            mn = min(mn, v[max(0, i - j)]);
        }
        cerr << mn <<" ";
    }
    dbg(__lg(29220));
}


// ll res = 0LL;
    // for(int i = n - 1; i >= 0; --i){
    //     ll mn = oo;
    //     int idx = i;
    //     for(int d = 1; d < 7; ++d){
    //         if(i - d < 0) break;
    //         ll cost = d * v[i - d];
    //         if(cost < mn){
    //             mn = cost;
    //             idx = i - d + 1;
    //         }
    //     }
    //     dbg(idx);
    //     res += (mn == OO);
    //     i = idx;
    // }

    // println(res);