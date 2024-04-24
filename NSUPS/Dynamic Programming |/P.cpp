#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 1000 + 69;
int n, l1, l2;

int64_t dp[N][N];

void solve(const int& tc){
    dp[0][0] = 1;
    for(int coin = 1; coin <= 300; ++coin)for(int price = 0; price < N ; ++price){
        if(price + coin >= N) continue;
        for(int num_coin = 0; num_coin < N; ++num_coin){
            dp[price + coin][num_coin + 1] += dp[price][num_coin];
        }   
    }
    for(int i = 0; i < N; ++i){
        for(int j = 1; j < N; ++j){
            dp[i][j] += dp[i][j - 1];
        }
    }

    string s;
    while(getline(cin, s)){
    vector<string> v = {""};
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                v.emplace_back("");
            }else{
                v.back() += s[i];
            }
        }
        l1 = l2 = -1;
        int op = 1; 
        if(int(v.size()) == 3){
            ::l2 = stoi(v[2]);
            ++op; 
        }
        if(int(v.size()) >= 2){
            ::l1 = stoi(v[1]);
            ++op;
        }
        ::n = stoi(v[0]);
        int64_t res = -1;
        if(op == 1){
            res = dp[n][1000];
        }else if(op == 2){
            res = dp[n][l1];
        }else if(op == 3){
            res = dp[n][l2] - (l1 > 0 ? dp[n][l1 - 1] : 0);
        }else{
            assert(false);
        }
        cout << res << '\n';
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
