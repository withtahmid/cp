#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>a(k);
        for(int i = 0; i < k; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        int64_t res = 0LL;
        for(int i = 1; i < k; ++i) res += (a[i] - 1) + a[i];
        cout << res << '\n';
    }
}
