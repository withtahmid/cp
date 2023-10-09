/**
 *
 * Author: withtahmid
 * Created: 2023-10-09 20:32:55
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
    cout << endl;
    dbg(__elapsed__());
}
void precompute(){}
void solve(const int case_no){
    
    string str;
    cin >> str;
    int x;
    cin >> x;
    int n = len(str);
    int itr = len(str);
    int prev = 0;
    int som = 0;
    int p = 1;
    while(n < x){
        som += itr;
        --itr;
        n += itr;
        ++p;
    }

    if(p == len(str) and len(str) > 1){
        cout << min(str[0], str[1]);
        return;
    }
    
    int indx = x - som;
    cout << str[indx-1];
}
