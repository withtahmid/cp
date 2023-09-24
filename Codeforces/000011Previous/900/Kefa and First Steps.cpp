/**
 * 
 * withtahmid
 * Twins
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
#define okbai return 0
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug(i) cout<<"I am here: "<<i "\n"
template <typename Type> void print(vector<Type>& v){for(Type& i : v) cout<<i<<" ";cout<<endl;}
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";cout<<"\n";}
int main()
{
	nn;
    vl(n);
    cin>>v;
    if(n==1)
    {
        cout<<1<<endl;
        okbai;
    }
    ll current  = v[0];
    ll result = -1;
    for(int i = 1; i < v.size();i++)
    {
        ll segment_size = 1;
        current = v[i-1];
        while(current <= v[i] && i < v.size())
        {
            ++segment_size;
            current = v[i];
            i++;
        }
        result  = max(result,segment_size);
    }
     cout << result << endl;
     okbai;
}