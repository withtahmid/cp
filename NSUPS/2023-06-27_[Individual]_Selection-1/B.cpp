/**
 * 
 * Author: withtahmid
 * Created: 2023-06-27 15:02:36
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
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

void print(auto dq){
    for(auto i : dq){
        cerr << "{"<<i.first <<" " << i .second<<"} ";
    }
    cerr << endl;
}

void solve(int case_no){
    int n;
    cin >> n;
    deque<pii>dq(n);
    for(int i = 0; i < n; ++i){
        cin >> dq[i].first >> dq[i].second;
    }
    sort(all(dq));
    ll res = 0LL;
    while(len(dq) > 1){
        auto buy = dq.front();
        auto sell = dq.back();
        // print(dq);
        if(sell.second < buy.second){
            ll profit = ((ll)sell.first * (ll)sell.second) - ((ll)buy.first*(ll)sell.second);
            res += profit;
            dq.pop_back(); 
            dq[0].second -= sell.second;
        }
        else if(sell.second > buy.second){
            ll profit = ((ll)sell.first * buy.second) - ((ll)buy.second*(ll)buy.first);
            dq[len(dq)-1].second -= buy.second;
            res += profit;
            dq.pop_front();
        }
        else{
            ll profit = ((ll)sell.first * (ll)sell.second) - ((ll)buy.first*(ll)sell.second);
            res += profit;
            dq.pop_back();
            dq.pop_front();
        }
        
    }
    cout << res << endl;
}