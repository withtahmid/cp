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
string str;
const int maxn = 1000 + 69;
int dp[maxn][5];
int fn(int i, int prev){
    if(i == (len(str) -1)){
        if(str[i] == '1'){
            return (prev == 3 ? 1 : 0);
        }
        else{
            return (prev == 2 ? 1 : 0);
        }
    }
    if(dp[i][prev] != -1){
        return dp[i][prev];
    }
    int cost = INT_MAX;
    if(prev == 0){
        if(str[i] == '0'){
            cost = min(cost, fn(i + 1, 0));
        }
        else{
            cost = _min(
                        cost,
                        fn(i + 1, 2),
                        fn(i + 1, 0) + 1
                    );
        }
    }
    else if(prev == 1){
        if(str[i] == '1'){
            cost = min(cost, fn(i + 1, 1));
        }
        else{
            cost = _min(
                        cost, 
                        fn(i + 1, 3),
                        fn(i + 1, 1) + 1
                    );
        }
    }
    else if(prev == 2){
        cost = min(cost, fn(i + 1, 2) + (str[i] == '1'? 0 : 1));
    }
    else if(prev == 3){
         cost = min(cost, fn(i + 1, 3) + (str[i] == '0' ? 0 : 1));
    }
    else{
        if(str[i] == '1'){
            cost = _min(
                    cost,
                    fn(i + 1, 1),
                    fn(i + 1, 0) + 1
                );
        }
        else{
            cost = _min(
                    cost,
                    fn(i + 1, 0),
                    fn(i + 1 , 1) + 1
                );
        }
    }
    return dp[i][prev] = cost;
}
void solve(const int case_no){
    cin >> str;
    if(len(str) <= 2){
        cout << 0 << endl;
        return;
    }
    memset(dp, -1, sizeof(dp));
    cout << fn(0, 4) << endl;
}
