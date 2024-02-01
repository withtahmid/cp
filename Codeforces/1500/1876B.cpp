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
    bool test_case = not true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 69;
const int mod = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
vector<ll>v(maxn), powerOfTwo(maxn);
void precompute(){
    powerOfTwo[0] = 1;
    for(int i = 1; i < maxn; ++i){
        powerOfTwo[i] = (2 * powerOfTwo[i -1]) % mod;
    }
}
void solve(const int case_no){
    int n;
    read(n);
    for(int i = 1; i <= n; ++i){
        read(v[i]);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; j += i){
            v[i] = max(v[i], v[j]);
        }
    }
    sort(v.begin() + 1, v.begin() + n + 1);
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        res = (res + (powerOfTwo[i - 1] * v[i])) % mod;
    }
    println(res);
}
 