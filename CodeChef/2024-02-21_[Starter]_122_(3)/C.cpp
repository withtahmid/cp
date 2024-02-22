/**
 *
 * Author: withtahmid
 * Created: 2024-02-21 20:24:23
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
string bin(long long n){
    int bit = 31;string res = string(bit, '0');
    for(int i = 0; i < bit; ++i)res[bit - i - 1] = ((n >> i) & 1) ? '1' : '0';
    return res;
}
void solve([[maybe_unused]] const int& case_no){
    int n;
    read(n);
    auto s = bin(n);
    reverse(all(s));
    dbg(s);
    int r = 0;
    for(int i = len(s) - 1; i >= 0; --i){
        if(s[i] == '1'){
            r = i;
            break;
        }
    }
    int l = 0;
    for(int i = 0; i < len(s); ++i){
        if(s[i] == '1'){
            l = i;
            break;
        }
    }
    assert(l <= r);
    int z = count(s.begin() + l, s.begin() + r + 1, '0');
    if(z == 0){
        return println(0);
    }
    ll N = 0LL;
    for(int i = r; i >= 0; --i){
        N |= (1LL << i);
        if(s[i] == '0'){
            return println(N - n);
        }
    }
}
