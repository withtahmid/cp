/**
 *
 * Author: withtahmid
 * Created: 2024-02-06 20:41:28
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
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void solve([[maybe_unused]] const int case_no){
    int n, m, k;
    read(n, m, k);
    vector<int> a(n), b(m);
    read(a);
    read(b);
    map<int, int>mp;
    for(const auto& i : a){
        if(i > k){
            continue;
        }
        mp[i] = 1;
    }
    for(const auto& i : b){
        if(i > k){
            continue;
        }
        if(has(mp, i) and mp[i] != 2){
            mp[i] = 69;
        }else{
            mp[i] = 2;
        }
    }
    int one = 0, two = 0;
    for(const auto[key, val] : mp){
        one += (val == 1), two += (val == 2);
    }
    println((one > k / 2 or two > k / 2 or len(mp) < k) ? "NO" : "YES");
}