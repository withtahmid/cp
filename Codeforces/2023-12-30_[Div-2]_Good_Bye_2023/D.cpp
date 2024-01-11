/**
 *
 * Author: withtahmid
 * Created: 2023-12-30 20:43:15
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
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }

    cout << string("196").append(n - 3, '0') << endl;

    for(int i = 0, j = 0; i <= n - 3; i += 2, ++j){
        cout << string("9")
                .append(j, '0')
                .append(1, '6')
                .append(j, '0')
                .append(1, '1')
                .append(n - (j * 2) - 3, '0') 
             << endl;

        cout << string("1")
                .append(j, '0')
                .append(1, '6')
                .append(j, '0')
                .append(1, '9')
                .append(n - (j * 2) - 3, '0') 
             << endl;
    }
}
