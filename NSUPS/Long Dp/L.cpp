/**
 * 
 * Author: withtahmid
 * Created: dd-mm-yy hh:mm
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...) 
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define len(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
const int maxn = 3000 + 10;
vector<ll>v(maxn);
ll dp[maxn][maxn][2];

vector<int> DP[10][10][2];

ll fn(int prev, int l, int r, ll x, ll y){
    if(l == r){
        return  (prev == 1 ? ( (x + v[l]) - y) : x - (y+v[l]));
    }
    // if(dp[l][r][prev] != -1LL){
    //     cerr << l <<" " << r << " " << prev<<": " << dp[l][r][prev] << endl;
    //     return dp[l][r][prev];
    // }

    if(prev == 1){
        ll res1 = fn(0, l+1, r, x + v[l], y);
        ll res2 = fn(0, l, r-1, x + v[r], y);
        
        dp[l][r][prev] = max(res1, res2);
        DP[l][r][prev].push_back(dp[l][r][prev]);
        return dp[l][r][prev];
    }
    else{
        ll res1 = fn(1, l+1, r, x, y + v[l]);
        ll res2 = fn(1, l, r-1, x, y + v[r]);
        
        dp[l][r][prev] = min(res1, res2);
        DP[l][r][prev].push_back(dp[l][r][prev]);
        return dp[l][r][prev];
    }
}

void solve(int case_no){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    memset(dp, -1LL, sizeof(dp));
    cout  << fn(1, 0, n-1, 0LL, 0LL) << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cerr << "{"<< dp[i][j][0] <<" " << dp[i][j][1] <<"}" <<" ";
        }cerr<<endl;
    }
     for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            cerr<< i <<" "<<j<<endl;
            debug(DP[i][j][0]);
            debug(DP[i][j][1]);
            cerr<<endl;
        }
    }
}