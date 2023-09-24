/**
 * 
 * Author: withtahmid
 * Created: 19-08-2022 17:09:00
 * 
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

void solve()
{
    test_case{
        int n,k;
        cin>>n>>k;
        if(k%4==0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(!(k&1))
        {
            bool track = true;
            for(int i = 1; i <= n; i += 2)
            {
                if(track){
                    cout << i+1 <<" " << i << endl;
                }
                else{
                    cout << i << " " << i+1 << endl;
                }
                track = !track;
            }
        }
        else
        {
            for(int i = 1; i<=n; i+= 2)
            {
                cout << i<<" " << i+1 << endl;
            }
        }
    }
}
int main()
{
	file_io();
    boostIO
    solve();
}
