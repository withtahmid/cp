/**
 *
 * Author: withtahmid
 * Created: 2023-09-30 17:57:53
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
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__);
}
void precompute(){}
void solve(const int case_no){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    dbg(s, t);
    string prefix = t.substr(0, n);
    string suffix = t.substr((m - n), string::npos);
    if(s == suffix and s == prefix){
        cout << 0 << endl;
    }
    else if(s == prefix){
        cout << 1 << endl;
    }
    else if(s == suffix){
        cout << 2 << endl;
    }
    else{
        cout << 3 << endl;
    }
}
