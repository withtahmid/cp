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
    int n, m;
    read(n, m);
    map<int, ll>mp_left, mp_right;
    for(int i = 0; i < n; ++i){
        int l, r;
        read(l, r);
        if((r - l + 1) == m){
            continue;
        }
        if(l == 1){
            ++mp_left[l];
            --mp_left[r + 1];
        }
        else if(r == m){
            ++mp_right[l];
            --mp_right[r + 1];
        }
        else{
            ++mp_left[l];
            --mp_left[r + 1];
            ++mp_right[l];
            --mp_right[r + 1];
        }
    }
    ll res = 0LL;
    ll sum = 0LL;
    for(auto[k, v] : mp_left){
        sum += v;
        res = max(res, sum);
    }
    sum = 0LL;
    for(auto[k, v] : mp_right){
        sum += v;
        res = max(res, sum);
    }

    println(res);
}
