/**
 *
 * Author: withtahmid
 * Created: 2023-12-19 20:32:24
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
const int maxn = 1e5 + 10;
int dp[maxn];
vector<ll> a, b, c;
int n;
int fn(int i, set<int>taken){
    if(i >= n){
        return 0;
    }
    
    if(dp[i] != -1){
        return dp[i];
    }

    ll res = fn(i + 1, taken);
    ll res_1 = -1, res_2 = -1, res_3 = -1;
    if(!taken.contains(0)){
        auto temp = taken;
        temp.insert(0);
        res_1 = fn(i + 1, temp) + _max(a[i], b[i], c[i]);
    }
    if(!taken.contains(1)){
        auto temp = taken;
        temp.insert(1);
        res_2 = fn(i + 1, temp) + _max(a[i], b[i], c[i]);
    }
    if(!taken.contains(2)){
        auto temp = taken;
        temp.insert(2);
        res_2 = fn(i + 1, temp) + _max(a[i], b[i], c[i]);
    }
}
void solve(const int case_no){
    
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    cin >> a;
    cin >> b;
    cin >> c;
    memset(dp, -1, sizeof(dp));
    cout << fn(0, set<int>()) << endl;
}
