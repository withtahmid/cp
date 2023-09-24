/**
 * 
 * Author: withtahmid
 * Created: 27-01-2023 20:32:23
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

void fun(vi& v, int l, int r){
    if(l == r){
        return;
    }
    sort(v.begin() + l, v.begin()+r+1);
    // sort(all(v));
    debug(v);
    int p = l;
    for(int i = l; i <= r; ++i){
        if(i != l){
            if(i == r){
                fun(v, p, i+1);
            }
            else if(abs(v[i] - v[i-1]) > 1 or i == r){
                fun(v, p, i);
                // for(int x = p; x < (i==r? i+1 : i ); x++){
                //     cerr<<v[x]<<" ";
                // }
                // cerr<<endl;
                p = i;
            }
        }
    }
}
void solve(int case_no){
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    fun(v, 0, n-1);
}
