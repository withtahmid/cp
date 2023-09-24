/**
 * 
 * Author: withtahmid
 * Created: 20-11-2022
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
#define print_case(case_no,ending) cout <<"Case "<<case_no<<":"<<ending
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i;}
typedef int_fast64_t ll;
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
    bool multiple_test_case = true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << endl << "\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
const int MAXN = 110;
vector<int>graph[MAXN];
vector<bool>visited(MAXN);
vector<int>res;
void reset(){
    res.clear();
    for(int i = 0; i < MAXN; ++i){
        graph[i].clear();
        visited[i] = false;
    }
}
void add_edge(int u, int v){
    graph[v].pb(u);
}
void DFS(int n){
    visited[n] = true;
    for(int i : graph[n]){
        if(!visited[i]){
            DFS(i);
        }
    }
    res.pb(n);
}
void TOP_SORT(int n){
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            DFS(i);
        }
    }
}
void solve(int case_no){
    reset();
    int n;
    cin >> n;
    vector<string>v(n);
    cin >> v;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int a = i + 1;
            int b = j + 1;
            if(v[i][j] == '1'){
                add_edge(a,b);
          
            }

        }
    }

    TOP_SORT(n);
    vector<int>result[n+2];

    for(int i = 0; i < n; ++i){
        
        for(int j = 1; j <= i+1; ++j){
            result[res[i]].pb(j);
        }
        if(result[res[i]].size()>1){
            int x = result[res[i]].size();
            result[res[i]][x-1] = n;
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << result[i].size() <<" ";
        for(int j : result[i]){
            cout << j <<" ";
        }
        cout<<endl;
    }
}