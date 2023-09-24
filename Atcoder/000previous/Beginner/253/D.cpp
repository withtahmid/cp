/**
 * 
 * Author: withtahmid
 * Created: 23-08-2022 17:12:11
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n";
#define nl cout<<"\n";
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define srt(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb push_back
#define decimal(n) fixed << setprecision(n)
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug cout<<"I am here\n";
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
ll lcm(ll a, ll b){
    return (a / __gcd(a, b)) * b;
}
int main()
{
	file_io();
    boostIO
    ll  n,a,b;
    cin>>n>>a>>b;
    ll lcm_ab = lcm(a,b);
    ll lcm_devides = n/lcm_ab;
    ll a_devides = n/a;
    ll b_devides = n/b;
    ll total = (n*(n+1))/2;
    ll result = total - ((a*(a_devides*(a_devides+1))/2) + (b*(b_devides*(b_devides+1))/2));
    cout << result + (lcm_ab*(lcm_devides*(lcm_devides+1))/2) << endl;  
}
