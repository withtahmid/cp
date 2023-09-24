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
const int MAXN = 1e5;
vector<int>exist(MAXN);
void solve(int case_no){
    ll n;
    cin >> n;
    vector<ll>v(n);
    fill(all(v), 0);
    cin >> v;
    // sort(all(v));
    debug(v);
    // debug(exist);
    for(int i = 0; i < n; ++i){
        const ll& num = v[i];
        ll sqt = sqrt(num);
        for(ll x = 2; x <= sqt; ++x){
            if(num%x == 0){
                ++exist[x];
                cerr << x <<" ";
                if(x*x != num){
                    exist[num/x]++;
                    cerr << num/x <<" ";
                }
                if(exist[x] > 1 or exist[num/x] > 1){
                    cout << "YES" << endl;
                    return;
                }
            }
        }cerr<<endl;
    }
    // debug(exist,0);
    cout << "NO" << endl;

}