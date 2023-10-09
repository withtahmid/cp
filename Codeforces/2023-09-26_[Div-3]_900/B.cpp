/**
 *
 * Author: withtahmid
 * Created: 2023-09-26 20:32:59
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
inline constexpr auto max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto min(const auto f, const auto... r){return min({f, r...});}
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
    dbg(__elapsed__);
}
void precompute(){}
void solve(const int case_no){
    int n;
    cin >> n;
    vector<ll>v = {2, 3};
    cout << 2 << " " <<  3 <<" ";
    for(int i = 3;  i <= n; ++i){
        ll it = v.back() + 1;
        while((3 * it) % (v[len(v) -1] + v[len(v) - 2]) == 0){
            ++it;
        }
        v.pb(it);
        cout << it <<" ";
    }
    cout << endl;
}
