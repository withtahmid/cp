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

/*REST*/

const int POS = 10;
int64_t dp[POS][9 * 10][2][2];

int64_t fn(const string& L, const string& R, int pos, int sum = 0, int l_tight = 1, int r_tight = 1){
    if(pos == -1){
        return isPrime[sum] ? 1 : 0;
    }
    int64_t& res = dp[pos][sum][l_tight][r_tight];
    if(res != -1 and not l_tight and not r_tight){
        return res;
    }
    res = 0;
    int lo = l_tight ? L[pos] - '0' : 0, hi = r_tight ? R[pos] - '0' : 9;
    for(int i = lo; i <= hi; ++i){
        res += fn(L, R, pos - 1, sum + i, (l_tight and (i == lo)), (r_tight and (i == hi)) );
    }
    return res;
}

int64_t digit_dp(string L, string R){
    reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
    while(int(L.size()) < int(R.size())){
        L.push_back('0');
    }
    return fn(L, R, int(L.size() - 1));
}

void solve(const int& tc){
    
    string a, b;
    
    cin >> a >> b;
    
    cout << digit_dp(a, b) << '\n';
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
