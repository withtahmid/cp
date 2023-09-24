#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		long long teams = pow(2,n);
		
		cout<<teams-1<<endl;
	}
}