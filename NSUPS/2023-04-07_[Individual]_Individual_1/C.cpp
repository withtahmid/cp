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
#define sizeof(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
template <typename Type>
void operator>>(istream& istream, deque<Type>& v){for(auto& i:v){cin>>i;}}
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
void solve(int case_no){
    ll n;
    cin >> n;
    n += 2;
    vector<ll>v(n);
    vector<ll>cost(n);
    for(int i = 2; i < n; ++i){
        cin >> v[i];
        cost[i] = 0;
    }
    
    v[0] = v[2];
    v[1] = v[2];
    cost[0] = 0;
    cost[1] = 0;

    for(int i = 2; i < n; ++i){

        ll cost_1 = abs(v[i] - v[i-1]) + cost[i-1];
        ll cost_2 = abs(v[i] - v[i-2]) + cost[i-2];
        cost[i] = min(cost_1, cost_2);
    }
    cout << cost[n-1] << endl;
}