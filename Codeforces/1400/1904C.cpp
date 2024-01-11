/**
 *
 * Author: withtahmid
 * Created: 2024-01-07 18:14:17
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
typedef int_fast64_t ll;
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
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
void solve(const int case_no){
    int n, k;
    read(n, k);
    vector<ll>v(n);
    read(v);
    if(k >= 3){
        println(0);
        return;
    }
    vector<ll>gaps;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            gaps.pb(abs(v[i] - v[j]));
        }
    }
    sort(all(v));
    sort(all(gaps));
    ll res = min(v[0], gaps[0]);
    if(k == 1){
        println(res);
        return;
    }

    auto closest = [&](ll x){
        int l = 0, r = len(gaps) - 1, m;
        while(l <= r){
            m = l + (r - l) / 2;
            if(gaps[m] < x){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return res;
    };
    
    for(int i = 0; i < n; ++i){
        res = min(res, abs(closest(v[i]) - v[i]));
    }
    println(res);
}