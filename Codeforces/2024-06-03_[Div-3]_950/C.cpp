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

const int N = 2e5 + 69;
int n, m, a[N], b[N], d[N];

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> d[i];
    }

    map<int, vector<int>>no_match_idx, match_idx;
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            no_match_idx[b[i]].emplace_back(i);
        }else{
            match_idx[b[i]].emplace_back(i);
        }
    }

    bool used = false;

    for(int i = m - 1; i >= 0; --i){
        if(len(no_match_idx[d[i]]) > 0){
            no_match_idx[d[i]].pop_back();
            used = true;
        }else if(len(match_idx[d[i]]) > 0){
            used = true;
        }else if(not used){
            cout << "NO\n";
            return;
        }
    }

    for(const auto& [num, vec] : no_match_idx){
        if(len(vec) != 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
   
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
