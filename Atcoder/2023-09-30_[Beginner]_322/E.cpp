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

const int maxn = 110;
const int maxk = 6; 
vector<ll>cost(maxn);
vector<vector<int>>plans(maxn, vector<int>(maxk, 0));
const ll oo = 1e13;
int n, k, p;
ll dp[maxn][maxk][maxk][maxk][maxk][maxk];

ll fn(int i, int a, int b, int c, int d, int e){
    int* arr[] = {&a, &b, &c, &d, &e};
    for(int x = 0; x < 5; ++x){
        if(*arr[x] > p){
            *arr[x] = p;
        }
    }
    
    if(i >= n){
        for(int x = 0; x < k; ++x){
            if(*arr[x] < p){
                return oo;
            }
        }
        return 0LL;
    }

    if(dp[i][a][b][c][d][e] != -1){

        return dp[i][a][b][c][d][e];
    }

    ll res_1 = fn(i + 1, a, b, c, d, e);

    ll res_2 = cost[i] +  fn(
            i + 1, 
            a + plans[i][0],
            b + plans[i][1],
            c + plans[i][2],
            d + plans[i][3],
            e + plans[i][4]
        );

    return dp[i][a][b][c][d][e] =  min(res_1, res_2);
}
void solve(const int case_no){
    
    cin >> n >> k >> p;
    for(int i = 0; i < n; ++i){
        cin >> cost[i];
        for(int j = 0; j < k; ++j){
            cin >> plans[i][j];
        }
    }

    mem(dp, -1);

    ll res = fn(0, 0, 0, 0, 0, 0);


    cout << (res >= oo ? -1LL : res) << endl;
}
