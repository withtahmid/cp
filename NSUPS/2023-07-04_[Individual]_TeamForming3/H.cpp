/**
 * 
 * Author: withtahmid
 * Created: 2023-07-04 15:15:50
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

void solve(int case_no){
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    vector<unordered_set<int>>all_prime_factors;
    for (int num : v) {
        unordered_set<int>primeFactors;
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                primeFactors.insert(i);
                while (num % i == 0) {
                    num /= i;
                }
            }
        }
        if (num > 1) {
            primeFactors.insert(num);
        }
        all_prime_factors.pb(primeFactors);
    }
    for(ll res = 2; ; ++res){
        int cnt = 0;
        for(auto each_num : all_prime_factors){
            for(auto num : each_num){
                if(res % num == 0){
                    ++cnt;
                    break;
                }
            }
        }
        if(cnt == n){
            cout << res << endl;
            break;
        }
    }
}