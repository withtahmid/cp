#include <bits/stdc++.h>
using namespace std;

void solve(const int& tc){
    int n;
    cin >> n;
    int res = 0, mx = 0;
    for(int x = 2; x <= n; ++x){
        int sum = 0;
        for(int multiple = x; multiple <= n; multiple += x){
            sum += multiple;
        }
        if(sum > mx){
            mx = sum, res = x;
        }
    }

    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
