/**
 *
 * Author: withtahmid
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) { ((cout << a), ...); }
inline void println(const auto &...a) { print(a..., '\n'); }
inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
inline void read(deque<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 10;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
const int block_size = ceil(sqrt(maxn));
void precompute(){}
struct node{
    int XOR_1  = 0, XOR_0 = 0;
};
void solve(const int case_no){
    int n;
    read(n);
    vector<int>v(n);
    string str;
    read(v);
    read(str);
    vector<node>block(block_size);
    for(int i = 0; i < n; ++i){
        const int idx = i / block_size;
        if(str[i] == '1'){
            block[idx].XOR_1 ^= v[i];
        }else{
            block[idx].XOR_0 ^= v[i]; 
        }
    }
    int q;
    read(q);
    while(q--){
        int op;
        read(op);
        if(op == 1){
            int l, r;
            read(l, r);
            --l, --r;
            for(int i  = l; i <= r;){
                const int idx = i / block_size;
                if( i % block_size == 0 and i + block_size <= r){
                    swap(block[idx].XOR_0, block[idx].XOR_1);
                    i += block_size;
                }else{
                    block[idx].XOR_1 ^= v[i];
                    block[idx].XOR_0 ^= v[i];
                    ++i;
                }
            }
        }else{
            int d;
            read(d);
            int res = 0;
            for(int i = 0; i < len(block); ++i){
                res ^= (d & 1 ? block[i].XOR_1 : block[i].XOR_0);
            }
            print(res, " ");
        }
    }
    println();
}
