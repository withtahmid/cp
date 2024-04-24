#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 60 + 9;

int a[N], n, q, W;

bool dp[1000 * N][N];

void solve(const int& tc){
    while(cin >> n >> q and (n != 0 and q != 0)){
        W = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i], W += a[i];
        }

        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i = 0; i < n; ++i){
            for(int w = W; w >= 0; --w){
                if(w - a[i] < 0) continue;
                for(int take = 1; take <= n; ++take){
                    dp[w][take] = dp[w][take] | dp[w - a[i]][take - 1];
                }
            }
        }
        while(q--){
            int w;
            cin >> w;
            // (not necessarily positive) integer W
            if(w > W or w < 1){
                cout << "That's impossible!\n";
                continue;
            }
            int possible = false;
            for(int i = 1; i <= n; ++i){
                if(dp[w][i] != 0){
                    possible = true;
                    cout << i << ' ';
                }
            }
            if(not possible){
                cout << "That's impossible!"; 
            }
            cout << '\n';
        }
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
