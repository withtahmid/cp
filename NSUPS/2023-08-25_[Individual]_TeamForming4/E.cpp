/**
 * 
 * Author: withtahmid
 * Created: 2023-08-25 14:54:19
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

const int N = 1e6;
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

bool isPrime_f(ll n){
    for(auto i : primes){
        if(i*i>n){
            return true;
        }
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void factors(map<ll, ll>& mp, ll n) {
  for (int p: primes) {
    if (p * p > n){ 
        break;
    }
    if (n % p == 0) {
      while (n % p == 0) {
        mp[p]++;
        n /= p;
      }
    }
  }
  if (n != 1) {
    mp[n]++;
  }
  // return result;
}

void solve(int case_no){
    sieve();
    ll a, b;
    cin >> a >> b;
    // factors(21);
    bool _a = isPrime_f(a), _b = isPrime_f(b);
    if(_a and _b and a != b){
        cout << "full credit" << endl;
        return;
    }
    else if(_a and _b and a == b){
        cout << "no credit" << endl;
        return;
    }
    map<ll, ll>mp;
    factors(mp, a);
    factors(mp, b);
    dbg(mp);
    for(auto it : mp){
        if(it.second > 1){
            cout << "no credit" << endl;
            return;
        }
    }
    cout << "partial credit" << endl;

}