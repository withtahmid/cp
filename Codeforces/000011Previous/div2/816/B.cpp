/**
 * 
 * Author: withtahmid
 * Created: 20-08-2022 20:29:22
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
int main()
{
    file_io();
    boostIO
    test_case{
        ll n,k,b,s;
        cin>>n>>k>>b>>s;
        long long y;     
        if(n==1)
        {
            if(k*b != s){
                cout << -1 << endl;
            }
            else{
                cout << s << endl;
            }
            continue;
        }
         y = s - (b*k);
         long long start = b*k;
         if(y >= k)
         {
            start += k-1;
            y -= k-1;
         }
         else if(y+start < (k+1)*b)
         {
            start = s;
            y = 0;
         }

        if(s < k*b || ((k-1)*(n-1)) < y)
        {
            cout << -1 << endl;
        }

        else
        {
            
            vector<long long>v;
            v.pb(start);
            long long sum = start;
            while(sum<s)
            {
                if(s-sum >= k){
                    v.pb(k-1);
                    sum += k-1;
                }
                else{
                    v.pb(s-sum);
                    sum += s-sum;
                }
                if(sum >= s){
                    break;
                }
            }           
            cout <<  v ;
             for(int i = 0; i< n-v.size(); i++)
            {
                cout << 0 << " ";
            }
            nl;
        }
    }   
}