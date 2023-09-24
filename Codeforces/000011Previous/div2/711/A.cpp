/**
 * 
 * Author: withtahmid
 * Created: 13-08-2022 16:52:18
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
ll gcd_sum(ll n)
{
    ll sum_of_digit = 0;
    ll digit = n;
    while(digit != 0)
    {
        sum_of_digit += digit%10;
        digit/=10;
    }
    return __gcd(sum_of_digit,n);
}
int main()
{
	file_io();
    boostIO
    test_case{
        lln;
        for(ll i = n; true; i++)
        {
            if(gcd_sum(i) > 1)
            {
                cout << i << endl;
                break;
            }
        }


    }
    
}
