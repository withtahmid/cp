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
ll dp[110][(int)1e5+10];
vector<item>v(110);
ll INF = 1e15+69;
ll knapsack(ll i, ll value){
    if(i < 0){
        if(value > 0){
            return INF;
        }
        return 0;
    }
    if(dp[i][value] != -1){
        return dp[i][value];
    }
    ll result = knapsack(i-1, value);
    if(value - v[i].v >= 0){
        result = min(result, v[i].w + knapsack(i-1, value-v[i].v));
    }
    return dp[i][value] = result;

}
void solve(int case_no){
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i){
        cin >> v[i].w >> v[i].v;
    }
    ll max_val = 0;
    for(int i = 0; i < n; ++i){
        max_val += v[i].v;
    }
    for(ll i = max_val; i > 0; --i){
        ll res = knapsack(n-1, i);
        if(res <= w){
            cout << i << endl;
            break;
        }
    }
}