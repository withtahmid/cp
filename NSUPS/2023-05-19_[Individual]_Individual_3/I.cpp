/**
 * 
 * Author: withtahmid
 * Created: 2023-05-19 10:26:15
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
vi binaryof(int n){
    vi v;
    while(n > 0){
        v.pb(n%2);
        n >>= 1;
    }
    reverse(all(v));
    return v;
}
void solve(int case_no){
    int n;
    cin >> n;
    vi v = binaryof(n);
    // debug(v);
    vi v1(len(v)), v2(len(v));
    bool first = true;
    for(int i = 0; i < len(v); ++i){

        if(v[i] == 1){
            if(first){
                v1[i] = 1;
                v2[i] = 0;
                first = false;
            }
            else{
                 v2[i] = 1;
                 v1[i] = 0;
            }
           
        }else{
            v1[i] = 1;
            v2[i] = 1;
        }
    }
    reverse(all(v1));
    reverse(all(v2));
    ll res1 = 0, res2 = 0;
    for(int i = 0; i < len(v); ++i){
        res1 += (1 << (i))*v1[i];
        res2 += (1 << (i))*v2[i];
    }
    cout << res1 * res2 << endl;
}