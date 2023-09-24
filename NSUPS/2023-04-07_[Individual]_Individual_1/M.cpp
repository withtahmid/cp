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
const int mod = 1e9 + 7;
const int maxn = 100+10;
const int maxk = 1e5 + 10;
ll dp[maxn][maxk];
int n, k;
vector<int>v(maxn);
ll fn(int i, int left){
    if(i == n){
        return (left == 0 ? 1 : 0);
    }
    if(dp[i][left] != -1){
        debug("okbai");
        return dp[i][left];
    }
    ll res = 0;
    for(int can = 0; can <= v[i] and left - can >= 0; ++ can){
        res += fn(i+1, left - can) % mod;
    }
    return dp[i][left] =  res;

}
void solve(int case_no){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << fn(0, k) << endl;
}