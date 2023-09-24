n/**
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
#define len(v) (int) v.size()
typedef int_fast64_t ll;
typedef long double ld;
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
const int maxn = 300 + 10;
int N;
// vector<int>v(maxn);
ld fn(vector<int>v){
    int zero = 0;
    for(int i = 0; i < N; ++i){
        if(v[i] == 0){
            ++zero;
        }
    }
    if(zero == 0){
        return 0;
    }
    ld res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(v[j] > 0){
                vector<int> temp_v = v;
                temp_v[j] -= 1;
                res += fn(temp_v);
            }
        }
    }
    ld res_2 = 0;
    ld div = (ld) n-zero;
    for(int i = 0; i < N; ++i){
        

    }

}

void solve(int case_no){
    cin >> N;
    vector<int>v(n+1);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

}