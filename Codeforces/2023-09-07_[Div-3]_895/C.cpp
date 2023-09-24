/**
 * 
 * Author: withtahmid
 * Created: 2023-09-07 20:32:41
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
    bool multiple_test_case = true;
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
const int N=1e7;
bool isPrime[N+1];
vector<int> primes;
void sieve(){
    for(int i=1; i<=N; i++){
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for(int i = 4; i<=N; i+=2){
        isPrime[i] = false;
    }
    for(int i=3; i*i <= N; i+=2){
        if(isPrime[i]){
            for(int j=i*i; j<=N; j+=2*i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=N; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

vector<pair<int, int>> prime_factorize_as_pair(int n) {
    vector<pair<int, int>> result;
    for (int p : primes) {
        if (p * p > n) {
            break;
        }
        if (n % p == 0) {
            int expo = 0;
            while (n % p == 0) {
                ++expo;n /= p;
            }
            result.push_back(make_pair(p, expo));
        }
    }
    if (n != 1) {
        result.push_back(make_pair(n, 1));
    }
    return result;
}

void before_tc(auto looad){
    sieve();
}
void solve(int case_no){
    int l , r;
    cin >> l >> r;
    if(r <= 3){
        cout << -1 << endl;
        return;
    }

    if((r&1) and (l == r)){
        auto res =  prime_factorize_as_pair(l);
        if(len(res) == 1 and res[0].second == 1){
            cout << -1 << endl;
            return;
        }
        cout << res[0].first << " " << l - res[0].first << endl;
        return;
    }

    int ans = ((r & 1) ? (r-1)/2 : r/2);
    
    cout << ans << " "  << ans << endl;
}