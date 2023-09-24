/**
 * 
 * Author: withtahmid
 * Created: 24-08-2022 18:44:36
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
int main()
{
	file_io();
    boostIO
    ll n;
    cin>>n;
    map<ll,ll>mp;
    ll max_input   = -1;
    ll min_input = 1e11+10;
    for(ll i = 0; i<n; i++)
    {
        ll input;
        cin>>input;
        max_input =  max(max_input, input);
        min_input = min(min_input,input);
        mp[input]++;
    }
    if(max_input == min_input)
    {
        --n;
        cout << 0 <<" "<< (n*(n+1))/2 <<endl;
    }
    else{
        cout << abs(max_input-min_input) <<" "<<mp[max_input] * mp[min_input] << endl;
    }
    
        
    
    
    
}
