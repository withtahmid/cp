/**
 * 
 * Author: withtahmid
 * Created: 31-03-2023 20:31:39
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
void solve(int case_no){
    int n, c, d;
    cin >> n >> c >> d;
    vector<int>arr(n);
    cin >> arr;
    deque<int>v;
    sort(all(arr));
    v.pb(arr[0]);
    for(int i = 1; i < n; ++i){
        if(arr[i]^v.back()){
            v.pb(arr[i]);
        }
    }
    ll cost = c *(arr.size() - v.size());
    if(v[0]!=1){
        v.push_front(1);
        cost += d;
    }
    ll min_cost = LLONG_MAX;
    n = sizeof(v);
    for(int i = 0; i < n; ++i){
        ll del = n - i - 1LL;
        ll add = v[i] - (i + 1LL);
        min_cost = min(min_cost, (del * c) + ( add * d));
    }
    cout << min_cost + cost << endl;

}
