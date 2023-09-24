/**
 * 
 * Author: withtahmid
 * Created: 11-12-2022
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
#define nl cout<<'\n';
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
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
    cerr << endl << "\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(int case_no){
    ll n, m;
    cin >> n >> m;
    set<pair<ll,ll>>enemy;
    vector<ll>v(n,INT_MAX);
    for(ll i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        --a, --b;
        if(a>b){
            swap(a,b);
        }
        v[a] = min(v[a], b);
    }
    ll mn = n, result = 0;
    for(ll i = n-1; i >= 0 ; --i){
       mn = min(mn, v[i]);
       result += mn - i;
    }
    cout << result <<endl;
}