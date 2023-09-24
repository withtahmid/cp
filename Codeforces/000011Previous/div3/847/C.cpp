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
    bool multiple_test_case =  true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(int case_no){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n-1));
    for(auto& i : v ){
        cin >> i;
    }
    for(int i = 0; i < n; ++i){
        vector<int> fst = v[i];
        fst.pop_back();
        debug(fst);
        for(int j = 0; j < n; ++j){
            vector<int>scnd(n-2);
            for(int x = 1; x < n-1; ++x){
                scnd[x-1] = v[j][x];
            }
            debug(scnd);
            if(fst == scnd){
                cout << v[j][0] <<" ";
                for(auto& x:v[i]){
                    cout << x <<" ";
                }
                cout<<endl;
                return;
            }
        }

    }


}
