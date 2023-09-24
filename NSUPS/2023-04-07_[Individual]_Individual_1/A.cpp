n/**
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
    bool multiple_test_case = true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

const ll mod = 10000007;
ll a, b, c, d, e, f;
vector<ll>dp(10000+10);
ll fn(ll n) {
    if(dp[n] != LONG_MIN){
        return dp[n];
    }
    if (n == 0) return a%mod;
    if (n == 1) return b%mod;
    if (n == 2) return c%mod;
    if (n == 3) return d%mod;
    if (n == 4) return e%mod;
    if (n == 5) return f%mod;
    dp[n] =  fn(n-1)%mod;
    for (int i = 2; i < 7; ++i){
        dp[n] = (dp[n] + fn(n-i))%mod;
    }
    return dp[n];
}

void solve(int case_no){
    fill(all(dp), LONG_MIN);
    cout << "Case "<<case_no<<": ";
    ll n;
    cin >> a >> b >> c >> d >> e >> f >> n;
    cout << fn(n) << endl;
}