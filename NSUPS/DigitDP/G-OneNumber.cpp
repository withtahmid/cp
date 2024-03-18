#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
vector<int> isPrime;
void sieve(const int N){
    isPrime.resize(N + 69, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 4; i <= N; i += 2){
        isPrime[i] = false;
    }
    for(int i = 3; i * i <= N; i += 2){
        for(int j = i * i; j <= N; j += (i << 1)){
            isPrime[j] = false;
        }
    }
}

const int POS = 10;
int64_t dp[POS][100][2];

int64_t fn(const string& s, int pos, int sum = 0, int tight = 1){
    if(pos == -1){
        return isPrime[sum] ? 1 : 0;
    }
    int64_t& res = dp[pos][sum][tight];
    if(res != -1 and not tight){
        return res;
    }
    res = 0;
    int hi = tight ? s[pos] - '0' : 9;
    for(int i = 0; i <= hi; ++i){
        res += fn(s, pos - 1, sum + i, (tight and (i == hi)));
    }
    return res;
}

int64_t go(string s){
    reverse(s.begin(), s.end());
    return fn(s, int(s.size()) - 1);
}

void solve(const int& tc){
    int l, r;
    cin >> l >> r;
    cout << go(to_string(r)) - go(to_string(l - 1)) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    sieve(100);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
