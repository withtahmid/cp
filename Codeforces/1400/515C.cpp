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
    string str;
    cin >> str;
    vector<int>res;
    for(auto i : str){
        int x = i - '0';
        if(x == 2 or x == 3 or x == 5 or x == 7){
            res.pb(x);
        }
        else if(x == 4){
            res.pb(3);
            res.pb(2);
            res.pb(2);
        }
        else if(x == 6){
            res.pb(5);
            res.pb(3);
        }
        else if(x == 8){
            res.pb(7);
            res.pb(2);
            res.pb(2);
            res.pb(2);
        }
        else if(x == 9){
            res.pb(7);
            res.pb(2);
            res.pb(3);
            res.pb(3);
        }
    }
    sort(all(res), greater<int>());
    for(auto i : res){
        cout << i;
    }
    cout << endl;
}
