#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

void solve(const int& tc){
    int64_t n, a, b;
    cin >> n >> a >> b;
    set<int64_t>st;
    for(int i = 0; i < n; ++ i){
        int64_t x;
        cin >> x;
        st.insert(x % (a + b) + 1);
    }
    dbg(st);
    auto conflict = [&](int64_t num) -> bool{
        auto lb = st.lower_bound(num + a);
        if(lb == st.end()){
            return false;
        }
        dbg(*lb);
        return(*lb < (num + a + b));
    };

    for(auto i : st){
        if(conflict(i)){
            dbg(i);
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
