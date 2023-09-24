/**
 * 
 * Author: withtahmid
 * Created: 21-08-2022 17:26:54
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
#define debug(n) cout<<"I am at "<<n<<"\n"
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
    int n,l;
    cin>>n>>l;
    vi(n);
    cin>>v; 
    srt(v);
    auto zero = lb(v,0);
    int last_distance;
    int first_distance;
    bool has_zero = true, has_l = true;
    if( *zero !=0 )
    {
        first_distance = *zero;
        has_zero = false;
    }
    auto len = lb(v,l);
    if(*len != l)
    {
        last_distance = l -  *(len-1);
        has_l = false;
    }
    int max_distance = -1;
    for(int i = 1; i<v.size(); i++)
    {
        max_distance = max(max_distance, abs(v[i] - v[i-1]));
    }
    if(!has_l)
    {
        max_distance = max(max_distance,last_distance*2);
    }
    if(!has_zero)
    {
        max_distance = max(max_distance, first_distance*2);
    }

    cout << decimal(12) << (long double)max_distance/2.0 <<endl;
    
}
