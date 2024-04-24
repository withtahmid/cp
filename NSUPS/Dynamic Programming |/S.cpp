#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif


vector<int> isPrime;
vector<int>primes;
void sieve(const int N = 1120){
    isPrime.resize(N + 69, true);
    isPrime[1] = false;
    for(int i = 4; i <= N; i += 2){
        isPrime[i] = false;
    }
    for(int i = 3; i * i <= N; i += 2){
        for(int j = i * i; j <= N; j += (i << 1)){
            isPrime[j] = false;
        }
    }
    for(int i = 0; i <= N; ++i){
        if(isPrime[i]){
            primes.emplace_back(i);
        }
    }
}

int64_t dp[190][20][1200];

int64_t fn(int i, int k, int n){
    if(i < 0 or n <= 0 or k <= 0){
        return n == 0 and k == 0 ? 1 : 0;
    }
    int64_t& res = dp[i][k][n];
    if(res != -1){
        return res;
    }
    res = fn(i - 1, k,  n);
    if(primes[i] <= n){
        res += fn(i - 1, k - 1, n - primes[i]);
    }
    return res;
}

void solve(const int& tc){
    int n, k;
    while(cin >> n >> k){
        if(n == 0 and k == 0){
            break;
        }
        memset(dp, -1, sizeof(dp));
        dbg(n, k);
        cout << fn(primes.size() - 1, k, n) << '\n';
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    sieve();
    dbg(primes.size());
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
