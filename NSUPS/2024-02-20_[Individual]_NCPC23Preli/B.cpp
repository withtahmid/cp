/**
 *
 * Author: withtahmid
 * Created: 2024-02-20 16:58:09
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
template<class T>
class SparseTable{
private:
    vector<vector<T>>sparse_table;
    function<T(T, T)> func;
    int n, lgn;
public:
    SparseTable(const vector<T>& v, const function<T(T, T)>& _func){
        this -> func = _func;
        this -> n = v.size();
        assert(n != 0);
        this -> lgn = __lg(v.size()) + 1;
        this -> sparse_table.resize(n, vector<T>(lgn));
        for(int i = 0; i < this -> n; ++i){
            this->sparse_table[i][0] = v[i];
        }
        for(int j = 1; j < lgn; ++j){
            for(int i = 0; i + (1 << j) - 1 < this->n; ++i){
                this->sparse_table[i][j] = this->func(this->sparse_table[i][j - 1], this->sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r){
        assert(0 <= l and r < this-> n and l <= r);
        int lgr = __lg((r - l + 1));
        return (this->func(this->sparse_table[l][lgr], this->sparse_table[r - (1 << lgr) + 1][lgr]));
    }
};

void solve([[maybe_unused]] const int& case_no){
    int n , q;
    read(n, q);
    vector<int>v(n);
    read(v);
    dbg(v);
    SparseTable<int> st(v, [&](int a, int b){return min(a, b);});
    while(q--){
        int l, r;
        read(l, r);
        dbg(l, r);
        println(st.query(l - 1, r - 1));
    }
}
