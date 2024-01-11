/**
 *
 * Author: withtahmid
 * Created: 2024-01-06 20:34:19
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
    bool test_case = true;
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
    vector<int>v(n);
    cin >> v;
    vector<int> s = {v[0]}, t;
    for(int i = 1; i < n; ++i){
        if(len(s) and len(t) and s.back() < t.back()){
            swap(s, t);
        }
        if(v[i] <= s.back()){
            s.pb(v[i]);
        }
        else if(len(t) == 0 or v[i] <= t.back()){
            t.pb(v[i]);
        }
        else{
            s.pb(v[i]);
        }
    }
    int res = 0;
    for(int i = 0; i + 1 < len(s); ++i){
        if(s[i] < s[i +1]){
            ++res;
        }
    }
    for(int i = 0; i + 1 < len(t); ++i){
        if(t[i] < t[i +1]){
            ++res;
        }
    }
    cout << res << endl;
}