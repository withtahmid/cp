/**
 *
 * Author: withtahmid
 * Created: 2023-10-12 20:31:49
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = 1e7 + 10;
bool isPrime[maxn + 1];
vector<int> primes;
void sieve() {
  for (int i = 1; i <= maxn; i++) {
    isPrime[i] = true;
  }
  isPrime[1] = false;
  for (int i = 4; i <= maxn; i += 2) {
    isPrime[i] = false;
  }
  for (int i = 3; i * i <= maxn; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= maxn; j += 2 * i) {
        isPrime[j] = false;
      }
    }
  }
  for (int i = 2; i <= maxn; i++) {
    if (isPrime[i]) primes.push_back(i);
  }
}

void precompute(){
    sieve();
}

vector<int> pf(int n) {
    vector<int> result;
    for (int p : primes) {
      if (p * p > n) break;
      while (n % p == 0) {
        n /= p;
        result.push_back(p);
      }
    }
    if (n != 1) {
      result.push_back(n);
    }
    return result;
  }

void solve(const int case_no){
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    map<int, int>mp;
    for(auto i : v){
        auto vec = pf(i);
        for(auto x : vec){
            ++mp[x];
        }
    }
    for(auto it : mp){
        if((it.second % n) != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
