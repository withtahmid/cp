/**
 * 
 * Author: withtahmid
 * Created: 2023-09-02 17:57:13
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
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
void solve(int);
void before_tc();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif
    
}
void before_tc(){}
void solve(int case_no){
    int n, d;
    ll p;
    cin >> n >> d >> p;
    vector<ll>v(n);
    cin >> v;
    sort(all(v));
    vector<ll>pf(n+10, 0LL);
    pf[1] = v[0];
    for(int i = 2; i <= n; ++i){
        pf[i] += pf[i-1] + v[i-1];
    }

    auto total_cost = [&](int batch){
        ll total_pass = batch * d;
        ll lefts = max((ll)(n - total_pass), (ll) 0);
        ll cost = (pf[lefts]) + (batch * p);
        return (ll) cost;
    };

    int low = 0, hi = n;
    ll res = accumulate(all(v), 0LL);
    for(int i = 0; i <= n; ++i){
        res = min(res, total_cost(i));
    }
    cout << res << endl;
}