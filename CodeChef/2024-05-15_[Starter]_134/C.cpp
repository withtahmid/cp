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
typedef long double ld;
typedef pair<int, int> pii;

#define int int64_t

const int N = 2e5 + 69;

static int n, a[N];

void solve(const int& case_no){
    
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    while(q--){
        int k;
        cin >> k;
        multiset < int > st;
    
        for(int i = 0; i < k; ++i){
            st.insert(a[i]);
        }
        dbg(st);
        while(len(st) > 1){
            auto bi = *st.rbegin(), bj = *prev(st.rbegin()), bk = *st.begin();
            st.erase(st.begin()), st.erase(st.lower_bound(bi)),  st.erase(st.lower_bound(bj));
            st.insert((bi + bj) - bk);
            dbg(st);    
        }
    
        cout << *st.begin() << ' ';
    
    }
    cout << '\n';
}

// partial solution

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
