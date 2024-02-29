/**
 *
 * Author: withtahmid
 * Created: 2024-02-27 20:29:55
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
ll dp[110][50];
void precompute(){
    memset(dp, -1, sizeof(dp));
}
void brutforce(){}
void solve([[maybe_unused]] const int& case_no){

    ll a, b, l;
    read(a, b, l);
    
    const auto _pow = [](ll base, ll expo) -> ll&{
        auto& res = dp[base][expo];
        if(res != -1){
            return res;
        }
        res = 1; 
        for(ll i = 1; i <= expo; ++i){
            res *= base;
        }
        return res;
    };

    set<ll>st;

    for(ll x = 0; _pow(a, x) <= l; ++x){
        for(ll y = 0; _pow(b, y) <= l; ++y){
            const auto& ax = _pow(a, x), by = _pow(b, y);
            if((l % (ax * by)) == 0){
                st.insert(l / (ax * by));
            }
        }
    }
    println(len(st));
}
