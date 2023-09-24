#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n);
		for(int& i: v) cin>>i;
		if(n==1)
		{
			cout<<"YES\n";
			continue;
		}
		stack<int>stk;
		bool yes = true;
		int count = 0;
		for(int i=1; i<n; i++)
		{
			if(v[i] - v[i-1] == 1){
				count = 0;
			}
			else if(v[i] - v[i-1] > 2)
			{
				yes = false;
				break;
			}
			else{
				count+=v[i] - v[i-1]-1;
			}

			if(count > 3)
			{
				yes = false;
				break;
			}


		}
		yes ? cout<<"YES\n" : cout<<"NO\n";
	}
}