/**
 * 
 * Author: withtahmid
 * Created: 31-03-2023 20:31:39
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

void solve(int case_no){
    vector<int>res;
    int n;
    cin >> n;
    if(not (n&1)){
        cout <<  -1 << endl;
        return;
    }

    if(n == 3){
        cout <<  1 <<endl<<2 << endl;
        return;
    }
    int layer = ceil(log2(n));
    --layer;

    ll l = 2 << (layer-1);
    ll r = 2 << (layer);
    while(l < r){
        if(not(l&1)){
            ++l;
        }
        if(not (r&1)){
            --r;
        }
        ll mid = (l+r)/2;
        if(mid<n){
            res.push_back(2);
            l = mid+1;
            
        }
        else{
            res.push_back(1);
            r = mid - 1;
            
        }
    }
    cout << sizeof(res)+1 <<endl <<2<<" ";
    for(int i = 0; i < sizeof(res); ++i){
        cout << res[i] << " ";
    }
    cout << endl;

}
