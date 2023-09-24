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
        set<string>st;
        vector<string>v;
        for(int i = 0; i < n; i++)
        {
            string str;
            cin>>str;
            st.insert(str);
            v.pb(str);
        }

        string result = "";
        for(int i = 0; i < n; i++)
        {
            bool yes = false;
            for(int j = 0; j<v[i].size(); j++)
            {
                string temp1 = "", temp2 = "";
                temp1 += v[i].substr(0,j);
                temp2 += v[i].substr(j,v[i].size());
                if(st.find(temp1)!=st.end() && st.find(temp2)!=st.end())
                {
                    yes = true;
                    break;
                }
            }
            yes ? result += '1' : result += '0';

        }
        cout<<result<<endl;
    }
}
