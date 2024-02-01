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
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
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
    int n;
    read(n);
    vector<ll>v(n);
    read(v);
    sort(all(v));
    ll x = 0, res = 0;
    int i  = 0, j = n - 1;
    while(i < j){
        if(x + v[i] >= v[j]){
            ll cut = v[j] - x;
            v[i] -= cut;
            x += cut;
            res += x  + 1;
            --j;
            x = 0;
            i += (v[i] == 0);
        }
        else{
            x += v[i ++];
        }
    }
    if(i > j){
        println(res);
    }
    else if(v[i] == 1){
        println(res + 1 + x);
    }
    else{
        ll cut = ((x + v[i]) / 2) - x;
        x += cut;
        v[i] -= (cut + x);
        println(res + x + 1 + (v[i]&1));
    }
}
