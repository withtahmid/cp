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


const int N = 1e5 + 69, B = 32;
static int64_t n, a[N];

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> bits[B];

    for(int i = 0; i < n; ++i){
        for(int mask = B - 1; mask >= 0; --mask){
            if((a[i] >> mask) & 1){
                bits[mask].emplace_back(a[i]);
                break;
            }
        }
    }

    for(int mask = 0; mask < B; ++mask){
        sort(all(bits[mask]));
    }

    vector<bool> taken(n, false);
    int f = max_element(a, a + n) - a;

    vector<int>res = { INT_MAX };

    for(int i = 0; i < n; ++i){
        int dig = res.back();
        bool matched = false;
        int max_mask = -1, max_res = 0;
        for(int mask = B - 1; mask >= 0; --mask){
            if(((dig >> mask) & 1) and len(bits[mask])){
                int rs = dig & bits[mask].back();
                if(rs > max_res){
                    max_res = rs, max_mask = mask;
                }
            }
        }
        if(max_mask != -1){
            res.emplace_back(max_res), bits[max_mask].pop_back();
        }
        else{
            int max_mask = -1, max_res = 0;
            for(int mask = B - 1; mask >= 0; --mask){
                if(len(bits[mask])){
                    int rs = dig & bits[mask].back();
                    if(rs >= max_res){
                        max_res = rs, max_mask = mask;
                    }
                }
            }
            dbg(max_mask, max_res);
            if(max_mask != -1){
                res.emplace_back(max_res), bits[max_mask].pop_back();
            }else{
                assert(false);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
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
