/**
 *
 * Author: withtahmid
 * Created: 2023-10-08 15:03:46
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
void brutforce(int n, int m, int k){
    vector<int>v(n + 1);
    int res = 0;
    map<int, int>lens;
    for(int i = m; i >= 0; --i){
        v[0] = i;
        for(int j = 1, mod = n; j <= n; ++j){
            v[j] = v[j-1] % mod;
            --mod;
        }
        // reverse(all(v));
        set<int>st;
        for(auto x : v) st.insert(x);
        lens[len(st)]++;
        if(len(st) == k){
            ++res;
        }
    }
    dbg(n, lens);
    cout  << res << endl;
}
void solve(const int case_no){
    ll n, m, k;
    cin >> n >> m >> k;

    if(k > 3){
        cout << 0 << endl;
        return;
    }

    if(k == 1){
        cout << 1 << endl;
        return;
    }

    ll two = ( m / n ) + min(n - 1, m);
    ll three = m - two;
    cout << (k == 2 ? two : three) << endl;

}
