/**
 *
 * Author: withtahmid
 * Created: 2024-01-14 17:58:55
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
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
const int mxd = 15;
ll dp[mxd][mxd * 10];
ll possible[mxd];
ll fn(int i, int sum, vector<int>v){
    if(i < 1){
        if(sum == 0) return 0;
        ll dig = 0;
        for(auto x : v){
            dig = (dig * 10 + x) % sum;
        }
        return (dig == 0 ? 1 : 0);
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    ll tot = 0;
    for(int d = 0; d < 10; ++d){
        auto t = v;
        t.pb(d);
        ll ret = fn(i - 1, sum + d, t);
        tot += ret;
        if(sum == 0){
            possible[i] = ret;
        }
    }
    // dbg(i, tot);
    return dp[i][sum] = tot;
}
void solve(const int case_no){
    memset(dp, -1, sizeof(dp));
    fn(14, 0, vector<int>());
    dbg();
    int cnt = 0;
    for(int i = 1; i < 1000; ++i){
        int temp = i;
        int sum = 0;
        while(temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        if(i % sum == 0){
            ++cnt;
        }
    }
    dbg();
    // string str;
    // read(str);
    // ll res = 0LL;
    // for(int i = 1; i < len(str); ++i){
    //     res += dp[i][0];
    // }
    // int dig_sum = str[0] - '0';
    // for(int i = 1; i < len(str); ++i){
    //     dig_sum += str[i] - '0';
    //     for(int j = 0; i < str[i] - '0'; ++j){
    //         res += dp[len(str) - j][dig_sum + j];
    //     }
    // }
    // for(int i = 1; i < str[0] - '0'; ++i){
    //     res += dp[len(str)][i];
    // }
    // println(res);
}
