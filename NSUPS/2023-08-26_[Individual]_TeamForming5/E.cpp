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
const int N = 2 * 1e6;
bool isPrime[N+1];
vector<int> primes;
void sieve(){
    for(int i=1; i <= N; i++){
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for(int i = 4; i<=N; i+=2){
        isPrime[i] = false;
    }
    for(int i = 3; i*i <= N; i += 2){
        if(isPrime[i]){
            for(int j= i*i; j<=N; j+=2*i){
                isPrime[j] = false;
            }
        }       
    }
    for(int i=2; i<=N; i++){
        if(isPrime[i]) 
            primes.push_back(i);
    }
}

void factors(map<int, ll>&mp, int n) {
    vi f;
    int temp = n;
    for (int p : primes) {
    if (p * p > n){ 
        break;
    }
    if (n % p == 0) {
      while (n % p == 0) {
        n /= p;
      }
      f.pb(p);
    }
  }
  if (n != 1) {
     f.pb(n);
  }
  for(int i : f){
    mp[i] += temp;
  }
}

void solve(int case_no){
    sieve();
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    map<int, ll>mp;
    for(int& i : v){
        factors(mp, i);
    }
    dbg(mp);
    ll sum = -1;
    int prime;
    for(auto it : mp){
        if(it.second > sum){
            sum = it.second;
            prime = it.first;
        }
    }
    int divisor = INT_MAX;
    for(int& i : v){
        if(i % prime == 0){
            divisor = min(divisor, i);
        }
    }

    dbg(sum, prime);
    ll res = 0;
    for(int& i : v){
        res += (i/divisor) * divisor;
    }
    cout << res << endl;
}