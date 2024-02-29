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
void precompute(){}
void brutforce(){}
void solve([[maybe_unused]] const int& case_no){
    int n;
    read(n);
    vector<int64_t>v(n);
    read(v);
    partial_sum(all(v), v.begin());

    const auto fn = [&](int l, int r, int64_t u) -> int64_t{
        if(r < l or n <= r){
            return -OO;
        }
        auto k = v[r] - (l > 0 ? v[l - 1] : 0);
        auto x = k - 1;
        return (u * k) - (x * (x + 1) / 2);
    };

    int q;
    read(q);
    for(int qq = 1; qq <= q; ++ qq){
        int left, u;
        read(left, u);
        -- left;
        auto l = left, r = n - 1;
        int idx = n - 1;
        int64_t mx = fn(left, n - 1, u);
        while(l <= r){
            
            auto mid = (l + r) >> 1;
            auto res1 = fn(left, mid + 1, u);
            auto res2 = fn(left, mid - 1, u);
            auto res = fn(left, mid, u);
            
            if(mx <= res1){
                mx = res1;
                idx = mid + 1;
            }
            if(mx <= res){
                mx = res;
                idx = mid;
            }
            if(mx <= res2){
                mx = res2;
                idx = mid - 1;
            }

            if(res1 > res2){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        print(idx + 1, " ");
    }
    println();
}
