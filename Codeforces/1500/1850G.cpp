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
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
    dbg(__init__());
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
    return 0;
}
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void solve([[maybe_unused]] const int case_no){
    int n;
    read(n);
    vector<pair<ll, ll>>v(n);
    read(v);
    const int ub = (2 * 1e9) + 10;
    map<ll, int>diff_x, diff_y, x, y;
    for(const auto& p : v){
        ++ x[p.first], ++y[p.second];
        ++ diff_x[p.first - p.second], ++ diff_y[(ub - p.first) - p.second];
    }
    ll res = 0LL;
    for(const auto& p : v){
        res += (x[p.first] - 1) + (y[p.second] - 1);
        res += diff_x[p.first - p.second] - 1;
        res += diff_y[(ub - p.first) - p.second] - 1;
    }
    println(res);
}