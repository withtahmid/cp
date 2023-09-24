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
// const int
// int mem[]
const int mod = 1000000007;
int gd(int n){
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0){
            return n/i;
        }
    }
    return 1;
}
void solve(int case_no){
    int n;
    ll res = 0;
    cin >> n;
    do{
        int divisor = gd(n);
        int per_group = n/divisor;
        n = per_group - 1;
        ll play = divisor * (n*(n+1))/2;
        res += play;
        res %= mod;
        n = divisor;
        debug(divisor);
        debug(res);

    }while(n > 1);
    cout << res << endl;
}