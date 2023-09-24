/**
 * 
 * Author: withtahmid
 * Created: 2023-06-01 14:42:14
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...)
#define dbg(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define len(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
typedef long double ld;
template<typename... Args>
void print(Args... args){auto rest = [](const auto& arg)
{cout << arg << " "; };(rest(args), ...);cout << endl;}
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

void solve(int case_no){
    int n, k;
    cin >> n >> k;
    vector<ll>v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    sort(all(v));
    for(int i = 1; i <= n; ++i){
        v[i] += v[i-1];
    }
    ll res = LLONG_MAX;
    for(int i = 0; i <= k; ++i){
        ll sum = v[i*2] + (v[n] - v[n - (k - i)]);
        res = min(res, sum);
    }
    cout << v[n] - res << endl;
}