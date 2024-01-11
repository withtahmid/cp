/**
 *
 * Author: withtahmid
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
    bool test_case = not true;
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
    vector <int> a(n);
    vector <int> b(n);

    cin >> a;
    cin >> b;

    vector <int> gap(n, 0);

    for(int i = 0; i < n; ++i){
        gap[i] = a[i] - b[i];
    }

    sort(all(gap));
    dbg(gap);

    ll res = 0LL;  
    for(int i = 0; i < n; ++i){
        int tol = 1 - gap[i];
        auto lb = lower_bound(gap.begin() + i  + 1 , gap.end(), tol);
        int cnt = gap.end() - lb;
        dbg(gap[i], tol, cnt);
        res += cnt;
    }
    cout << res << endl;
}
