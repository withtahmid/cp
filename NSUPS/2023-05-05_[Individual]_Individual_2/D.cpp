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
    bool multiple_test_case = true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
inline ll sqr(int a){
    return a*a;
}
const int maxn = 100 + 5;
ll dp[maxn][3];
int n;
ll fn(int idx, vector<int>v1, vector<int>v2){
    if(idx >= n){
        debug(v1);
        debug(v2);
        return 0;
    }
    ll sum1 = 0;
    for(int i = 0; i <= idx; ++i){
        for(int j = i+1; j <= idx; ++j){
            sum1 += sqr(v1[i] + v1[j]) + sqr(v2[i] + v2[j]);
        }
    }
    auto t1 = v1, t2 = v2;
    swap(v1[idx], v2[idx]);
    ll sum2 = 0;
    for(int i = 0; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            sum2 += sqr(v1[i] + v1[j]) + sqr(v2[i] + v2[j]);
        }
    }
    ll res = 0;
    if(sum1 < sum2){
        res = fn(idx + 1, t1, t2);
    }else{
        res = fn(idx + 1, v1, v2);
    }
    res += min(sum1, sum2);
    return res;

}
void solve(int case_no){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    vector<int>v1(n), v2(n);
    cin >> v1;
    cin >> v2;
    cout << fn(0, v1, v2) << endl;
}