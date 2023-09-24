/**
 * 
 * Author: withtahmid
 * Created: 2023-05-26 15:54:48
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
    bool multiple_test_case = true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
class gpu{
public:
    int v, w;
    gpu(){};
    
};
const int maxn = 26;
int n, b;
ll p;
vector<gpu> v(maxn);
int dp[maxn][(int)1e6+1];

ll fn(int i, int w){
    if(i >= n){
        return 0;
    }
    if(dp[i][w] != -1){
        return dp[i][w];
    }
    ll res = fn(i + 1, w);
    if(w + v[i].w <= b){
        ll res2 = fn(i + 1, w + v[i].w) + v[i].v;
        res = max(res, res2);
    }

    return dp[i][w] = res;
}

void solve(int case_no){
    memset(dp, -1, sizeof(dp));
    cin >> n >> p >> b;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str >> v[i].v >> v[i].w;
    }
    cout << "Case "<<case_no<< ": " << ceil(ceil((long double)p/fn(0, 0))/24.0) << endl;

}