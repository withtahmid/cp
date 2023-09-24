/**
 * 
 * withtahmid
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define nl cout<<endl
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb(n) push_back(n)
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug(i) cout<<"I am here: "<<i "\n";
template <typename Type> void print(vector<Type>& v){for(Type& i : v) cout<<i<<" ";cout<<endl;}
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";cout<<"\n";}
int main()
{
	boostIO
    test_case{
        nn;
        vl(n);
        cin>>v;
        if(v[0] == 1)
        {
            cout<<"YES\n";
            continue;       
        }
        bool yes = true;
        for(int i = 1; i<n; i++)
        {
            if(v[i]%v[0]!=0)
            {
                yes = false;
                break;
            }
        }
        cout<< (yes ? "YES\n" : "NO\n");
    }
}
