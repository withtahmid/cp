#include <bits/stdc++.h>
 using namespace std;
int main()
{
    
    int t=1;
    cin>>t;
    while(t--)
    {
        int l,r,a;
        cin>>l>>r>>a;
        int m =r % a;
        int  mx=r/a+r%a;
        int r1=r-(m + 1);
        if (l <= r1 &&r1 <= r){
            mx = max(mx, r1/a+r1%a);
        }
        cout<<mx<<endl;
    }
    return 0;
}