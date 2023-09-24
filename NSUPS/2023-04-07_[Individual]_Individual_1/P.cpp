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
const int maxn = 1e5 + 9;
const int BLACK = 0;
vector<int>graph[maxn];
vector<bool>visited(maxn);
ll fn(int n, int prev){
    ll res = 0;
    if(prev != 1){
        for(auto i : graphp[n]){
            res += fn(i, 1) + 1;
        }
    }
    if(prev != 0){
        for(auto i : graph[n]){
            res += fn(i, 0) + 2;
        }
    }
}
void solve(int case_no){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << fn(1, -1) << endl;
}