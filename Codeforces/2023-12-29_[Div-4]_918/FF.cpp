/**
 *
 * Author: withtahmid
 * Created: 2023-12-29 19:02:07
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
void precompute(){}
void solve(const int case_no){
    int n;
    cin >> n;
    vector<pii>v(n);
    for(auto& i : v){
        cin >> i.first >> i.second;
    }
    
    sort(all(v));
    dbg(v);
    set<int>st;
    
    ll res = 0;

    for(int i = n - 1; i >= 0; --i){
        auto s = st.lower_bound(v[i].second);
        auto f = st.lower_bound(v[i].first);
        res += s - f;
        st.insert(v[i].second);
        dbg(i, v[i], st, res);
    }

    cout << res << endl;

}
