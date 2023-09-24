#include<bits/stdc++.h>
using namespace std;
int main()

{
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long o = 0;
		while(n--)
		{
			int temp;
			cin>>temp;
			o |= temp;
		} 
		cout<<o<<endl;
	}
}