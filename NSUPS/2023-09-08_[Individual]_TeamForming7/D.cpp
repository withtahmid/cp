/**
 *
 * Author: withtahmid
 * Created: 2023-09-08 10:08:07
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
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
void solve(int);
void before_tc(auto);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = not true;
    before_tc(1);
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif

}

void before_tc(auto looad){}
void solve(int case_no){
     
    const int N = 1e6 + 10;
    const ll mod = 1e4;
    
    vector<ll>v(N);
    
    v[0] = 1;
    
    for(int i = 1; i < N; ++i){
        
        v[i] = i * v[i-1];
        
        while(v[i] % 10 == 0){
            v[i] /= 10;
        }

        v[i] %= mod;
    }

    int n;
    cin >> n;
    while(n != 0){
        cout << v[n] % 10 << endl;
        cin >> n;
    }
}
