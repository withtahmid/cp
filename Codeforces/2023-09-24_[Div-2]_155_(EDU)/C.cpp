/**
 *
 * Author: withtahmid
 * Created: 2023-09-24 20:29:50
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
void solve([[maybe_unused]] const int case_no){
    string str;
    cin >> str;
    
    const int n = len(str);
    const ll mod = 998244353;
    
    auto cal = [](ll x){
        ll res = 1;
        for(ll i = 1; i <= x; ++i){
            res *= i;
            res %= mod;
        }
        return (ll) res;
    };

    ll way = 1;
    ll res = 0;
    
    for(int i = 1; i < n; ++i){
        int cnt = 1;
        while(i < n and str[i] == str[i-1]){
            ++i;
            ++ cnt;
        }
        way = (cnt * way) % mod;
        res += cnt - 1;
    }
    cout << res << " " << (way * cal(res)) % mod << endl;
}
