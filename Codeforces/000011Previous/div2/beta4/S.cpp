#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define I_am_starting_in_the_name_of_Allah ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define pi acos(-1)
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)

int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll tc; cin>>tc;
    ll cnt = 0;
    while(tc--)
    {
        ll n,k;cin>>n>>k;
        bool ok = true;
        set<ll>s;
        for(ll i=1;i*i<=(n-k);++i)
        {
            if((n-k)%i==0)
            {
                if(k<i)
                {
                    ok = false;
                    s.insert(i);
                }
                ll z = (n-k)/i;
                if(z>k && z!=i)
                {
                    ok = false;
                    s.insert(z);
                }
            }
        }
        if(ok)
        {
            cout<<"Case "<<++cnt<<": "<<"impossible"<<endl;
        }
        else
        {
           cout<<"Case "<<++cnt<<": "; 
           for(auto it: s)
            cout<<it<<" ";
        cout<<endl;
        }


    }
    
    return 0;

}