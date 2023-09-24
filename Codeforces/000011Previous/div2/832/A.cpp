/**
 * 
 * Author: withtahmid
 * Created: 04-11-2022
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
#define endl "\n"
#define nl cout<<"\n";
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define fil(v,n) fill(v.begin(), v.end(),n)
#define mem(v,value) memset(&v[0], value, sizeof(v[0]) * v.size())
#define acu(v) accumulate(v.begin(), v.end(),0LL)
#define pb push_back
#define sp(n) fixed << setprecision(n)
#define loop(l,r)  for(int i = l; i<r; ++i)
#define loopj(l,r)  for(int j = l; j<r; ++j)
#define test_case int t, tc = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define PRINT_CASE(tc) cout << "Case "<<tc<<": "
#define fast_io  ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}
typedef int_fast64_t ll;
typedef vector<int> vi;
typedef vector<int_fast64_t>vll;
typedef pair<int,int> pii;
void solve();
void local()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/T A H M I D/Desktop/Codes/input.txt", "r", stdin);
    freopen("C:/Users/T A H M I D/Desktop/Codes/output.txt", "w", stdout);
    freopen("C:/Users/T A H M I D/Desktop/Codes/error.txt", "w", stderr);
    #endif
}
int main()
{
    fast_io;
    local();
    time_t Time; time(&Time);cerr<<ctime(&Time)<<endl;
    auto starttime = chrono::steady_clock::now();
    test_case{
        solve();
    }
    cerr<<endl<<"\nElapsed time: "<<chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    cout <<abs(sum)<< endl;
}