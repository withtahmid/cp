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
        vi(n);
        cin>>v;
        for(int i = 0; i<n; i++)
        {
            int p;
            cin>>p;
            string str;
            cin>>str;
            for(int j=0; j<p; j++)
            {
                if(str[j] == 'D')
                {
                    v[i]++;
                    if(v[i]>9)
                        v[i] = 0;
                }
                else
                {
                    v[i]--;
                    if(v[i]<0) 
                        v[i] = 9;
                }
            }
        }
        cout<<v;
    }


}
