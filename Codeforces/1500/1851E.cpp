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
const int maxn = (2 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
ll dp[maxn];
void precompute(){}
ll cost_fn(int n, const vector<vector<int>>& recipy, const vector<int>& v){
    if(dp[n] != -1){
        return dp[n];
    }
    if(len(recipy[n]) == 0){
        return dp[n] = v[n];
    }
    ll res = 0;
    for(auto& i : recipy[n]){
        res += cost_fn(i, recipy, v);
    }
    
    return dp[n] = min(res, (ll)v[n]);
}
void solve([[maybe_unused]] const int case_no){
    int n, k;
    read(n, k);
    vector<int>v(n + 1);
    for(int i = 1; i <= n; ++i){
        read(v[i]);
    }
    for(int i = 0; i < k; ++i){
        int in;
        read(in);
        v[in] = 0;
    }

    vector<vector<int>>recipy(n + 1);
    for(int i = 1; i <= n; ++i){
        int sz;
        read(sz);
        recipy[i].resize(sz);
        read(recipy[i]);
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; ++i){
        print(cost_fn(i, recipy, v), " ");
    }
    println();
}
