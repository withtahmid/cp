/**
 * 
 * Author: withtahmid
 * Created: 11-10-2022 14:43:58
 * 
 * */

#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define nl cout<<"\n";
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb push_back
#define decimal(n) fixed << setprecision(n)
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug(n) cout<<"I am at line: "<<n<<"\n";
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
    fast_io;
    test_case{
        int n;
        cin>>n;
        vector<int>v1(n);
        vector<int>v2(n);
        cin>>v1;
        cin>>v2;
        if(v1 == v2)
        {
            cout << 0 << endl;
            continue;
        }
        int count1 = 0;
        for(int i = 0; i<n; i++)
        {
            v1[i] == v2[i] ? count1 : ++count1;
        }
        srt(v1);
        srt(v2);
        int count2 = 1;
        for(int i = 0; i<n; i++)
        {
            v1[i] == v2[i] ? count2 : ++count2;
        }
        cout << min(count1, count2) << endl;
    }
}
