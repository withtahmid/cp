#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

const int N = 2e5;
static int n, a[N];

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    multiset<int>st;
    
    int64_t tot = 0, res = 0;
    
    for(int i = 0; i < n; ++i){
        st.insert(a[i]), tot += a[i], res += (*st.rbegin() == (tot - *st.rbegin()));
    }

    cout << res << '\n';
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
