/**
 * 
 * Author: withtahmid
 * Created: 19-11-2022 18:00:54
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
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i;}
typedef vector<int> vi;
typedef vector<int_fast64_t>vll;
typedef pair<int,int> pii;
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
    int testcase = 1; if(!testcase){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << endl << "\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
pii next_minute(pii P){
    int a = P.first;
    int b = P.second;
    b += 1;
    if(b > 59){
        b = 0;
        a += 1;
    }
    if(a > 23){
        a = 0;
    }
    return {a,b};

}
bool confusing(pii P){
    int n = P.first, m = P.second;
    int a,b,x,y;
    b = n%10;
    n/=10;
    a = n%10; 
    y = m%10;
    m/=10;
    x = m%10;
    return (((a*10)+x) < 24) and (((b*10)+y) < 60);
}
void solve(int case_no){
    pii P;
    cin >> P.first >> P.second;

    while(!confusing(P)){
        P = next_minute(P);
    }
    cout << P.first <<" " << P.second << endl;
    


}
