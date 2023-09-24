/**
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
const int maxn = 2999 + 10;
int n;
vector<ld>v(maxn);
ld dp[maxn][maxn/2];
inline bool equal(ld a, ld b){
    return abs(a-b) < 1e-9;
}
ld fn(int i, int tail){
    if(i == 0 and tail == 0){
        return v[0];
    }
    if(i == 0 and tail > 0){
        return (ld)1;
    }
    if(not equal(-1, dp[i][tail])){
        return dp[i][tail];
    }
    if(tail == 0){
       return dp[i][tail] =  v[i] * fn(i-1, 0);
    }
    return dp[i][tail] =   (v[i]*fn(i-1, tail)) + ((1-v[i])*fn(i-1, tail-1));


}

void solve(int case_no){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            dp[i][j] = -1;
        }
    }
    cout<<sp(12) << fn(n-1, (n-1)/2) << endl;
}