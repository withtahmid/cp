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
    dbg(__init__());
    precompute();
    bool test_case =  true;
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
    ll n, m, d;
    read(n, m, d);
    vector<ll>v(m);
    read(v);
    ll prev = 1;
    vector<ll>co(m);
    auto gap = [&](ll l, ll r){
        return (ll)(abs(r - l) / d);
    };
    for(int i = 0; i < m; ++i){
        co[i] = gap(prev, v[i] - 1) + 1;
        prev = v[i];
        if(i > 0){
            co[i] += co[i - 1];
        }else{
            co[i] += v[0] != 1 ? 1 : 0; 
        }
    }
    if(n - v.back() >= d){
        co.pb(co.back() +  gap(v.back(), n));
    }
    vector<ll>rm(m);
    ll tot = co.back();
    if(v[0] == 1){
        rm[0] = tot;
    }else{
        rm[0] = tot - ((gap(1, v[0] - 1) + 1 + gap(v[0], v[1] - 1) + 1) - (gap(1, v[1] - 1) + 1));
    }
    if(v[m - 1] == n){
        rm[m - 1] = tot - ((gap(v[m - 2], n - 1) + 1) - (gap(v[m - 2], n)));
    }else{
        rm[m - 1] = tot - ((gap(v[m - 2], v[m - 1] - 1) + 1 + gap(v[m - 1], n)) - (gap(v[m - 2], n)));
    }
    for(int i = 1; i + 1 < m; ++i){
        rm[i] = tot - ((gap(v[i - 1], v[i] - 1) + 1 + gap(v[i], v[i + 1] - 1) + 1) - (gap(v[i - 1], v[i + 1] - 1) + 1));
    }
    ll mn = *min_element(all(rm));
    ll cnt = count(all(rm), mn);
    println(mn, " ",  cnt);
}
 