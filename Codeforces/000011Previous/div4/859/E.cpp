/**
 * 
 * Author: withtahmid
 * Created: 11-02-2023
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...) 
#endif
// #define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define sizeof(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
template <typename Type>
void operator>>(istream& istream, deque<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // io();
    // #endif
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
    int n;
    cin >> n;
    deque<ll> v(n);
    cin >> v;
    for(int i = 1; i < n; ++i){
        v[i] += v[i-1];
    }
    v.push_front(0);
    int l = 1, r = n, mid, ans;
    while(l <= r){
        mid = (l+r)/2;
        int range = r - mid + 1;
        cout << "? "<<range<<" ";
        for(int i = mid; i <= r; ++i){
            cout << i <<" ";
        }cout<<endl;
        
        cerr<<"...."<<l<<" "<<mid << " " <<r<<endl;
        
        ll expected_sum  = v[r] - v[mid-1];
        
        debug(expected_sum);
        ll answer_sum;
        cin >> answer_sum;
        if(answer_sum == expected_sum){
            r = mid-1;
        }
        else{
            ans = mid;
            l = mid+1;
        }
    }
    cout << "! " <<ans<<endl;

}
