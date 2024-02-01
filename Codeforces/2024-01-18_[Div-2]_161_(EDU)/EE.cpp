/**
 *
 * Author: withtahmid
 * Created: 2024-01-18 20:31:47
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
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
inline void print(const auto &...a) {((cout << a), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto &...a) {return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__arrt__());
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void solve(const int case_no){
    ll x;
    read(x);
    int msb;
    for(int i = 63; i >= 0; --i){
        if((x >> i)&1){
            msb = i;
            break;
        }
    }
    vector<int>arr;
    int negative = -1000;
    for(int i = 1; i <= msb; ++i){
        arr.pb(i);
    }
    vector<int>res;
    for(int i = len(arr) - 1, j = 0; j < len(arr); --i, ++j){
        if((x >> j)&1){
            res.pb(neg_curr ++);
        }
        res.pb(arr[i]);
    }
    reverse(all(res));
    println(len(res));
    for(auto& i : res){
        print(i, " ");
    }
    println();
}
