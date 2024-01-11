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
inline void read(vector<auto>& v) {for(auto& i : v){ cin >> i;}}
inline void read(deque<auto>& v) {for(auto& i : v){ cin >> i;}}
inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...);}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (2 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
void solve(const int case_no){
    const vector<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int n;
    read(n);
    vector<ll>v(n);
    read(v);
    
    int N = (1 << len(p));

    auto noCoprime = [v](ll x){
        for(auto& i : v){
            if(__gcd(i, x) == 1){
                return false;
            }
        }
        return true;
    };

    ll res = accumulate(all(p), 1LL, multiplies<ll>());
    for(int mask = 0; mask < N; ++mask){
        ll x = 1;
        for(int i = 0; i < len(p); ++i){
            if((mask >> i) & 1){
                x *= p[i];
            }
        }
        if(noCoprime(x)){
            res = min(res, x);
        }
    }

    println(res);
}
