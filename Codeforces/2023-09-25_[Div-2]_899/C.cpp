/**
 *
 * Author: withtahmid
 * Created: 2023-09-25 20:31:05
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
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init(0);
    bool test_case = true;
    before_tc();
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    init(1);
}
void before_tc(){}
int n;
const int maxn = 2e5 + 10;
int v[maxn];
ll dp[maxn][2];

ll fn(int i, int odd){
    if(i >= n){
        return 0LL;
    }

    if(dp[i][odd] != -1){
        return dp[i][odd];
    }

    ll res = fn(i + 1, odd ^ 1);

    if(odd){
        res = _max(
                res, 
                fn(i + 1, 1) + v[i],
                fn(i + 1, 0) + v[i]
            );
    }

    else{
        res = _max(
                res, 
                fn(i + 1, 1),
                fn(i + 1, 0)
            );
    }

    return dp[i][odd] = res;

}

void solve([[maybe_unused]] const int case_no){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    mem(dp, -1);
    cout << fn(0, 1) << endl;
}
