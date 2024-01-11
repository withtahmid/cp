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
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
void precompute(){}
map<int, bool>state;
bool fn(int n){
    if(state.contains(n)){
        return state[n];
    }
    if(n&1 or (n == 2)){
        return true;
    }
    vector<int>divs;
    for(int i = 2; i*i <= n; ++i){
        if(n % i != 0){
            continue;
        }
        if(i&1){
            divs.pb(n/i);
        }
        if((n/i)&1 and (i*i != n)){
            divs.pb(n/(n/i));
        }
    }
    if(len(divs) == 0){
        return false;
    }
    bool res = false;
    for(auto& i : divs){
        res |= !fn(i);
    }
    return state[n] = res;

}
void solve(const int case_no){
    int n;
    cin >> n;
    if(n == 1){
        cout << "FastestFinger" << endl;
        return;
    }
    cout << (fn(n) ? "Ashishgup" : "FastestFinger") << endl;
}
