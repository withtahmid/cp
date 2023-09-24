/**
 * 
 * Author: withtahmid
 * Created: 2023-04-07 10:00:13
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
char grid[1010][1010];
ll dp[1010][1010];
int h, w;
const int mod  = 1e9 + 7;
ll fn(int x, int y){
    if(x <= 0 and y <= 0){
        dp[x][y] = 1;
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    if(grid[x][y] == '#'){
        dp[x][y] = 0;
        return 0;
    }
    ll up = 0;
    ll left = 0;
    if(x > 0){
        left = fn(x-1, y)%mod;
    }
    if(y > 0){
        up = fn(x, y-1)%mod;
    }
    dp[x][y] = (up + left)%mod;
    return dp[x][y];

}
void solve(int case_no){
    memset(dp, -1, sizeof(dp));
    cin >> h >> w;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> grid[i][j];
        }
    }

   cout<< fn(h-1,w-1) << endl;
}