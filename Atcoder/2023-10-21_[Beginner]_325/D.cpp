/**
 *
 * Author: withtahmid
 * Created: 2023-10-21 17:58:41
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

int n;
const int maxn = 1e5 + 69; 
map<pair<int,ll>, int>dp;
vector<pii>v(maxn);

int fn(int i, ll time){
    if(i == n){
        return 0;
    }
   
    if(dp.find({i, time}) != dp.end()){
        return dp[{i, time}];
    }

    int res = fn(i + 1, time);

    if(time <= v[i].first + v[i].second){


        res = max(res, 1 + fn(i + 1, time + 1));
    }

     return dp[{i, time}] = res;
}

void solve(const int case_no){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.begin() + n, [](pii a, pii b){
        
    });
    cout << fn(0, 0) << endl;

}
