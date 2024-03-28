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
    isPrime[1] = false;
    for(int i = 4; i <= N; i += 2){
        isPrime[i] = false;
    }
    for(int i = 3; i * i <= N; i += 2){
        for(int j = i * i; j <= N; j += (i << 1)){
            isPrime[j] = false;
        }
    }
}

const int maxLen = 12;
int64_t dp[maxLen][2][2][50][50];

int64_t fn(const string& L, const string& R, int pos, int LT, int RT, int evenSum, int oddSum){
    if(pos == -1){
        int n = evenSum - oddSum;
        if(n < 2){
            return false;
        }
        return isPrime[n];
    }
    int64_t& res = dp[pos][LT][RT][evenSum][oddSum];
    if(res != -1 and not LT and not RT){
        return res;
    }
    res = 0;
    int lo = LT ? L[pos] - '0' : 0, hi = RT ? R[pos] - '0' : 9;
    for(int i = lo; i <= hi; ++i){
        res += fn(L, R, pos - 1,  (LT and (i == lo)), (RT and (i == hi)), ((pos + 1) & 1 ? evenSum : evenSum + i), ((pos + 1) & 1 ? oddSum + i : oddSum));
    }
    return res;
}

int64_t go(string L, string R){
    reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
    L = L  + string(R.length() - L.length(), '0');
    return fn(L, R, int(R.size()) - 1, 1, 1, 0, 0);
}
void solve(const int& tc){
    string l, r;
    cin >> l >> r;
    cout << go(l, r) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve(100);
    memset(dp, -1, sizeof(dp));
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
