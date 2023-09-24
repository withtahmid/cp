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
		for(int& i : v)
			cin>>i;
		
		int even_indx = v[1]%2;
		int odd_indx = v[0]%2;

		int yes  = true;
		for(int i = 0 ; i<n; i++)
		{
			if(i%2==1)
			{
				if(v[i]%2 != even_indx)
				{
					yes = false;
					break;
				}
			}
			else
			{
				if(v[i]%2 != odd_indx)
				{
					yes = false;
					break;

				}
			}
		}

		if(yes)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
}