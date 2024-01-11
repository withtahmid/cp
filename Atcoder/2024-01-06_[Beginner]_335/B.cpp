/**
 *
 * Author: withtahmid
 * Created: 2024-01-06 17:58:21
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
#define has(x, y) (x.find(y) != x.end())
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
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
const int maxn = (1 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
void solve(const int case_no){
    int n;
    cin >> n;
    for(int i  = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            for(int k = 0; k <= n; ++k){
                if(i + j + k <= n){
                    cout << i << " " << j << " " << k << endl; 
                }
            }
        }
    }
}
