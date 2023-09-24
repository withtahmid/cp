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
typedef int_fast64_t ll;
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
map<ll, set<ll>>graph;
void add_edge(ll u, ll v){
    graph[u].insert(v);
}
void remove_edge(ll u, ll v){
    graph[u].erase(v);
}
bool connected(ll u, ll v){
    return (graph[u].find(v) != graph[u].end()) and (graph[v].find(u) != graph[v].end());
}
void solve(int case_no){
    for(auto i : graph){
        i.second.clear();
    }
    int n, q;
    cin >> n >> q;
    while(q--){
        ll t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            add_edge(a,b);
        }
        else if(t == 2){
            remove_edge(a,b);
        }
        else{
            cout << (connected(a,b) ? "Yes" :"No") << endl;
        }
    }
    
} 
