#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

vector<int>spf;
void sieve(const int N = 1000000){
    spf.resize(N + 10);
    for(int i = 2; i <= N; ++i){
        spf[i] = i;
    }
    for(int i = 4; i <= N; i += 2){
        spf[i] = 2;
    }
    for(int i = 3; i * i <= N; ++i){
        if(spf[i] == i){
            for(int j = i * i; j <= N; j += (i << 1)){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> primeFactors(int n){
    vector<int>factors;
    while(n != 1){
        factors.emplace_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

#define len(x) int(x.size())  

void solve(const int& tc){
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto& i : v) {
        cin >> i;
    }
    map<int, set<int>> mp;

    for(int i = 0; i < n; ++i){
        auto f = primeFactors(v[i]);
        for(auto j : f){
            mp[j].insert(i);
            if(len(mp[j]) > 1){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n"; 

}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    sieve(2 * 1e5 + 69);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
