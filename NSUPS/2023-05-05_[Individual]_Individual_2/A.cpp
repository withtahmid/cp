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
    bool multiple_test_case = not true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(int case_no){
    string str;
    cin >> str;
    vector<int>v(len(str)+1);
    v[0] = 0;
    for(int i = 0; i + 1 < len(str); ++i){
        v[i+1] = ((str[i] == str[i+1]) ? 1 : 0);
        v[i+1] += v[i];
    }
    debug(v,0);
    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << v[r-1] - v[l-1] << endl;
    }
}