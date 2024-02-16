/**
 *
 * Author: withtahmid
 * Created: 2024-02-07 20:29:53
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
const int maxn = (1e6) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
int v[maxn];
void solve([[maybe_unused]] const int case_no){
    int n;
    read(n);
    map<int, pii>idx;
    for(int i = 0; i < (n * 2); ++i){
        read(v[i]);
        if(has(idx, v[i])){
            idx[v[i]].second = i;
        }else{
            idx[v[i]].first = i;
        }
    }
    vector<pii>arr;
    for(const auto& [key, val] : idx){
        arr.pb({key, abs(val.first - val.second)});
    }
    sort(all(arr), [](pii x, pii y){
        return x.second > y.second;
    });
    for(const auto& i : arr){
        print(i.first , " ");
    }
    println();
}