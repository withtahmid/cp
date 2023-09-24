/**
 *
 * Author: withtahmid
 * Created: 2023-09-18 20:24:19
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
#define sp(n) setprecision(n)
#define len(v) ((int) v.size())
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){print(args..., '\n');}
inline void print(vector<auto>& v){for(auto& i:v){cout << i << ' ';}cout << endl;}
inline void print(vector<auto>& v, char sep){for(auto& i:v){cout << i << sep;}cout << endl;}
void solve(int);
void before_testcase();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = true;
    before_testcase();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif

}
void before_testcase(){}
void solve([[maybe_unused]] const int case_no){
    int n, m;
    cin >> n >> m;
    vector<int>onea(40,0), oneb(40, 0);
    vector<ll>a(n), b(m);
    cin >> a;
    cin >> b;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 40; ++j){
            if((a[i] >> j)&1){
                ++onea[j];
            }
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < 40; ++j){
            if((b[i] >> j)&1){
                ++oneb[j];
            }
        }
    }
    int exora = a[0];
    for(int i = 1; i < n; ++i){
        exora^= a[i];
    }
    
    if(n&1){
        int mx = 0;
        for(int i = 0; i < 40; ++i){
            if(oneb[i] != 0 or (onea[i]&1)){
                mx += (1 << i);
            }
        }
        cout << exora << " " << mx << endl;
        return;
    }
    int mx = 0;
    for(int i = 0; i < 40; ++i){
        if(oneb[i] == 0 and (onea[i]&1)){
            mx += (1 << i);
        }
    }
    cout << mx << " " << exora << endl;
    

}
