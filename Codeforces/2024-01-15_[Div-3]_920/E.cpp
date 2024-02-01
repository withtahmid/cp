/**
 *
 * Author: withtahmid
 * Created: 2024-01-15 20:33:29
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
    bool test_case = true;
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
int h, w;
map<pair<ll, ll>, bool>dp;
const int AX[] = {-1, 0, +1};
const int BX[] = {-1, 0, +1};
inline bool valid(int x, int y){
    return 0 <= x and 0 <= y and y <= h and x < w;
}
bool fn(ll xa, ll ya, ll xb, ll yb){
    if(yb > ya){
        return false;
    }
    if(ya - 1 == yb){
        for(int i = 0; i < 3; ++i){
            if(AX[i] + xa == ya and ya -1 == yb){
                return true;
            }
        }
        return false;
    }
    pair<ll, ll> state;
    state.first = (xa | (ya << 32));
    state.second = (xb | (yb << 32));
    if(has(dp, state)){
        return dp[state];
    }
    bool res = false;
    for(int i = 0; i < 3; ++i){
        bool yes = true;
        for(int j = 0; j < 3; ++j){
            if(valid(xa + AX[i], ya-1) and valid(xb + BX[j], yb + 1)){
                yes &= fn(xa + AX[i], ya-1, xb + BX[j], yb + 1);
            }
        }
        res |= yes;
    }
    return dp[state] = res;
}
void solve(const int case_no){
    int xa, ya, xb, yb;
    read(xa, ya, xb, yb);
    dbg(fn(xa, ya, xb, yb));
}
