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
inline bool read(auto& x){return(cin >> x) ? true : false;}
inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
void solve(int);
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
    return 0;
}
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
ll dp[maxn][10];
vector<vector<int>>v(3, vector<int>(maxn));
int n;
ll fn(int i, int taken){
    if(i >= n or taken == 7){
        return 0LL;
    }
    if(dp[i][taken] != -1){
        return dp[i][taken];
    }
    ll res = fn(i + 1, taken);
    for(int mask = 0; mask < 3; ++mask){
        if(((taken >> mask) & 1) == 0){
            res = max(res, fn(i + 1, (taken + (1 << mask))) + v[mask][i]);
        }
    }
    return dp[i][taken] = res;
}
void solve([[maybe_unused]] const int case_no){
    read(n);
    for(int i = 0; i < 3; ++i) for(int j = 0; j < n; ++j){
        read(v[i][j]);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 8; ++j){
            dp[i][j] = -1;
        }
    }
    println(fn(0, 0));
}
