#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find() != v.end()))
typedef long double ld;
typedef pair<int, int> pii;
#define int int64_t 

const ld ESP = 1e-12;
const int N = 2e5 + 69;
int a[N], t[N],  n;

bool ok(int A, int B, int X) {
    return (X * logl(A)) <= logl(B);
}
void solve(const int& case_no){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        t[i] = a[i];
    }

    sort(a, a + n);


    int res = 0;
    for(int i = 0; i < n; ++i){
        int l = 0, r = 1e9 + 69;
        auto x = i + 1, B = t[i];
        int lim = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(ok(mid, B, x)){
                lim = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        res += (upper_bound(a, a + n, lim) - a);
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
