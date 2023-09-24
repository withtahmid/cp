/**
 * 
 * withtahmid
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define nl cout<<"\n"
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb push_back
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug(i) cout<<"I am here: "<<i "\n";
template <typename Type> void print(vector<Type>& v){for(Type& i : v) cout<<i<<" ";cout<<endl;}
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";cout<<"\n";}
int main()
{
	boostIO
    test_case{
        long long n,l,r;
        cin>>n>>l>>r;
        vector<long long>v;
        set<long long>s;
        long long current = 1; 
        for(long long i = l; i <=r ; i++)
        {
            long long GCD = __gcd(current,i);
            if( s.find(GCD) == s.end())
            {
                s.insert(GCD);
                v.pb(i);
                current++;
                i = l;
            }
            if(v.size()==n)
                break;
        }
        if(v.size()==n){
            cout<<"YES\n";
            cout<<v;
        }
        else
            cout<<"NO\n";
    }


}
