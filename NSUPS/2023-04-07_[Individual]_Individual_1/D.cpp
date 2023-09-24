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
class item{
public:
    int w;
    int v;
    item(){}
    item(int x, int y){
        w = x;
        v = y;
    }
};
int n,w;
const int MAXN = 110;
vector<item>v(MAXN);
ll dp[110][(int)1e5+10];
ll knapsack(int i, ll t_w){
    debug(i);
    if(i >= n or t_w > w){
        return 0;
    }
    if(dp[i][t_w] != -1){
        return dp[i][t_w];
    }
    if(v[i].w + t_w > w){
        return knapsack(i+1, t_w);
    }

    ll taken = knapsack(i+1, t_w + v[i].w);
    ll not_taken = knapsack(i+1, t_w);
    dp[i][t_w] = max(v[i].v + taken, not_taken);
    return dp[i][t_w];
}
void solve(int case_no){
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i){
        cin >> v[i].w >> v[i].v;
    }
    cout << knapsack(0, 0) << endl;
}