/**
 * 
 * Author: withtahmid
 * Created: 19-11-202
 * 
 * */
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <debug.h> 
#define debug(...) cerr<<"[" << #__VA_ARGS__ <<"] --> "; _debug(__VA_ARGS__); cerr << endl
#else
#define debug(...) 
#endif
using namespace std;
#define endl '\n'
#define nl cout<<"\n";
#define pb push_back  
#define all(v) v.begin(),v.end()
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define fil(v,n) fill(v.begin(), v.end(),n)
#define mem(v,value) memset(&v[0], value, sizeof(v[0]) * v.size())
#define sp(n) fixed << setprecision(n)
#define print_case(case_no,ending) cout <<"Case "<<case_no<<ending
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i;}
typedef int_fast64_t ll;
typedef vector<int> vi;
typedef vector<int_fast64_t>vll;
typedef pair<int,int> pii;
#define 
void solve(int);
void test();
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
    int m, s;
    cin >> m >> s;
    vi v(m);
    cin >> v;
    vector<bool>exist(1010, false);
    fil(exist,false);
    int mx = -1;
    for(int i = 0; i < m; ++i){
        if(exist[v[i]]){
            cout << "NO" << endl;
            return;
        }
        exist[v[i]] = true;
        mx = max(mx,v[i]);
    }
    for(int i = 1; s > 0; ++i){
        if(s < i){
            cout << "NO" << endl;
            return;
        }
        if(!exist[i]){
            exist[i] = true;
            s -= i;
            mx = max(mx,i);
        }
        
    }
    for(int i = 1; i <= mx; ++i){
        if(!exist[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}