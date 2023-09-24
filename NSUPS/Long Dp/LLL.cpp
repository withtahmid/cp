/**
 * 
 * Author: withtahmid
 * Created: dd-mm-yy hh:mm
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
class point{
public:
    ll x, y;
    point(){
        x = -1LL;
        y = -1LL;
    }
    point(ll a, ll b){
        x = a;
        y = b;
     }
};
point maxX(point a, point b){
    if((a.x - a.y) > (b.x - b.y)){
        return a;
    }
    return b;
}
point maxY(point a, point b){
    if((a.x - a.y) < (b.x - b.y)){
        return a;
    }
    return b;
}

const int maxn = 3000 + 10;
vector<ll>v(maxn);
point dp[maxn][maxn][2];
point fn(int prev, int l, int r){
    
    if(l == r){
        if(prev == 1){
            return point(v[l], 0LL);
        }
        else{
            return point(0, v[l]);
        }
    }
    if(dp[l][r][prev].x != -1LL and dp[l][r][prev].y != -1LL ){
        return dp[l][r][prev];
    }

    if(prev == 1){
        point res_1 = fn(!prev, l+1, r);
        res_1.x += v[l];
        point res_2 = fn(!prev, l, r-1);
        res_2.x += v[r];
        return  dp[l][r][prev] =  maxX(res_1, res_2);
    }
    else{
        point res_1 = fn(!prev, l+1, r);
        res_1.y += v[l];
        point res_2 = fn(!prev, l, r-1);
        res_2.y += v[r];
        return dp[l][r][prev] =  maxY(res_1, res_2);
    }

}

void solve(int case_no){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    point a = fn(1, 0, n-1);
    cout  << a.x - a.y << endl;
}