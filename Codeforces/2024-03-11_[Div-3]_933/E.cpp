/**
 *
 * Author: withtahmid
 * Created: 2024-03-11 20:32:39
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline bool read(auto &...x) { return (((cin >> x) ? 1 : 0) && ...); }
inline void print(const auto &...x) {((cout << x), ...); }
inline void println(const auto &...x) { print(x..., '\n'); }
void solve([[maybe_unused]] const int& case_no){
    int n, m, k, d;
    read(n, m, k, d);
    vector<vector<int>>grid(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            read(grid[i][j]);
            ++grid[i][j];
        }
    }
    
    auto fn = [&](auto& v) -> int64_t{
        if(len(v) <= d){
            return v.front() + v.back();
        }
        vector<int64_t> arr(len(v));
        multiset<int64_t> st = { v.front() };
        arr[0] = v.front();
        for(int i = 1; i < len(v); ++i){
            if(i - d - 1 > 0){
                st.erase(st.find(arr[i - d - 2]));
            }
            arr[i] = *st.begin() + v[i];
            st.insert(arr[i]);
        }
        return arr.back();
    };

    vector<int64_t> ans(n);
    for(int i = 0; i < n; ++i){
        ans[i] = fn(grid[i]);
    }
    partial_sum(all(ans),ans.begin());
    int64_t res = LLONG_MAX;
    for(int i = k - 1; i < n; ++i){
        res = min(res, (ans[i] - (i - k + 1 == 0 ? 0 : ans[i - k])));
    }
    println(res);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(__case__(tc));
        solve(tc);
    }
    dbg(__elapsed__());
}
