/**
 * 
 * Author: withtahmid
 * Created: 2023-07-05 14:58:39
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
#define sp(n) fixed << setprecision(n)
#define len(v) ((int) v.size())
#define vec vector
#define forn(n) for(int i = 0; i < n; ++i)
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline bool in(auto&...args) { return (((cin >> args) ? true : false) && ...);}
inline void in(vector<auto>&v){for(auto&i:v){in(i);}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T maxx(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T minn(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
vector<int>profits;
vector<ll> v;
ll n, k;
map<pair<int, ll>, ll>dp;
ll fun(int idx, ll mask){
    if(idx >= 63){
        return 0;
    }
    if((1 << idx) > k){
        return 0;
    }
    if(dp.find(make_pair(idx, mask)) != dp.end()){
        return dp[make_pair(idx, mask)];

    }

    ll res_1 = 0LL;
    for(int i = 0; i < n; ++i){
        res_1 += mask ^ v[i];
    }
    
    ll new_mask = 1 << idx;
    new_mask |= mask;

    if(new_mask > k){
        ll res = res_1 +  fun(idx + 1, mask);
        dp[make_pair(idx , mask)] = res;
        return res;
    }
    
    ll res_2 = 0LL;
    for(int i = 0; i < n; ++i){
        res_2 += new_mask ^ v[i];
    }

    ll res = max(
            res_1 +  fun(idx + 1, mask),
            res_2 +  fun(idx + 1, new_mask)
        );
    dp[make_pair(idx, mask)] = res;
    return res;

}

void solve(int case_no){
    cin >> n >> k;
    v.resize(n);
    cin >> v;
    cout << fun(0, 0LL) << endl;
}