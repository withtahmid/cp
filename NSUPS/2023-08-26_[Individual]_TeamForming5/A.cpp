/**
 * 
 * Author: withtahmid
 * Created: 2023-08-26 16:28:19
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
    bool multiple_test_case = true;
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


bool isPrime(int n){
    for(int i = 2; i*i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void f(int n){
    int divs = 0, pri = 0;
    for(int i = 2; i*i <= n; ++i){
        if(n % i == 0){
            ++divs;
            if(isPrime(i)){
                ++pri;
            }
            if(i* i != n){
                ++divs;
            }
        }
    }
    if(pri > (divs/2) + divs%2){
        cout << divs <<" " << pri <<" " << n << endl;
    }
}

void solve(int case_no){
    int x, k;
    cin >> x;
    cout << (k <= x/2 + x % 2 ? 0 : 1) << endl; 
}