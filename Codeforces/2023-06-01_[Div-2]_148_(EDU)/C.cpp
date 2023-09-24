/**
 * 
 * Author: withtahmid
 * Created: 2023-06-01 14:42:14
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...)
#define dbg(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define len(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
typedef long double ld;
template<typename... Args>
void print(Args... args){auto rest = [](const auto& arg)
{cout << arg << " "; };(rest(args), ...);cout << endl;}
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

int slop(int a, int b){
    return a > b ? 1 : -1;
}

void solve(int case_no){
    int n;
    cin >> n;
    vi t(n);
    cin >> t;
    vi v;
    v.pb(t[0]);
    for(int i = 1; i < len(t); ++i){
        if(v[len(v)-1] != t[i]){
            v.pb(t[i]);
        }
    }
    if(len(v) <= 2){
        cout << len(v) << endl;
        return;
    }
    auto turning = [&](int i){
        return  (v[i-1] > v[i] and v[i] < v[i+1]) or
                (v[i-1] < v[i] and v[i] > v[i+1]);
    };
    int res = 0;
    for(int i = 1; i + 1 < len(v); ++i){
        res += turning(i);
    }
    cout << res + 2 << endl;
}