/**
 *
 * Author: withtahmid
 * Created: 2023-10-12 20:31:49
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
void solve(const int case_no){
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    dbg(x, s);

    auto contains = [](const string& a, const string& b){
        if(len(a) < len(b)){
            return false;
        }
        for(int i = 0; i + len(b) - 1 < len(a); ++i){
            if(a.substr(i, len(b)) == b){
                return true;
            }
        }
        return false;
    };

    int res = 0;
    
    while(len(x) < 1000){
        if(contains(x, s)){
            cout << res << endl;
            return;
        }
        x += x;
        ++ res;
    }
    cout << -1 << endl;
}
