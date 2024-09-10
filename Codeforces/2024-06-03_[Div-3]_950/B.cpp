#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

void solve(const int& tc){
    
    int n, f, k;
    cin >> n >> f >> k;
    
    vector<int>v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int fav_num = v[f - 1];
    sort(all(v), greater<int>());

    int first_index = n - 1, last_index = 0;
    for(int i = 0, j = n - 1; i < n; ++i, --j){
        if(v[i] == fav_num){
            first_index = min(first_index, i);
        }
        if(v[j] == fav_num){
            last_index = max(last_index, j);
        }
    }
    
    if(last_index <= (k - 1)){
        cout << "YES\n";
    }else if(first_index > (k - 1)){
        cout << "NO\n";
    }else{
        cout << "MAYBE\n";
    }

}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
