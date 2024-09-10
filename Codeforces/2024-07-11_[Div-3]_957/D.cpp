#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 69;
int64_t n, m, k, dp[N];
char s[N];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 1; i <= n; ++i){
            cin >> s[i];
        }
        dp[n + 1] = 0;
        for(int i = n; i >= 0; --i){
            if(i != 0 and s[i] == 'C') {
                dp[i] = 1LL << 31;
            }
            else if(i != 0 and s[i] == 'W' and i < n + 1) {
                dp[i] = dp[i + 1] + 1;
            }
            else {
                dp[i] = 1LL << 31;
                for(int j = 1; j <= m; ++j){
                    if(i + j  <= n + 1){
                        dp[i] = min(dp[i], dp[i + j]);
                    }
                }
            }
        }
        cout << ( dp[0] > k ? "NO" : "YES") << '\n';
    }
}


    int max1=0;
    ll sum1=0;
    int cnt=0;
    int cnt1=0;
    int max2=0;
    int max3=0;
    int cnt5=0;

