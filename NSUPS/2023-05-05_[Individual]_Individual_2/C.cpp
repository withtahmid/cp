/**
 * 
 * Author: withtahmid
 * Created: 2023-05-05 09:58:52
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
const int maxn = 1e5 + 10;
int n;
vector<int>row1(maxn), row2(maxn);
ll dp[maxn][3];
ll fn(int i, int prev){
    if(i > n){
        return 0;
    }
    if(dp[i][prev] != -1){
        return dp[i][prev];
    }
    ll res = 0;
    if(prev != 1){
        res = fn(i + 1, 1) + row1[i];
    }
    if(prev != 2){
        res = max(res, row2[i] + fn(i + 1, 2));
    }
    res = max(res, fn(i + 1, 0));
    return dp[i][prev] = res;
}
void solve(int case_no){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> row1[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> row2[i];
    }
    cout << fn(0,0) << endl;

}