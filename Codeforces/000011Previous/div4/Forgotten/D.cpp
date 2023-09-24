#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int x = 0;
	while(t--)
	{
		int n;
		cin>>n;
		
		cin.ignore();
		
		string str;
		cin>>str;

		if(n==1)
		{
			cout<<"NO\n";
			continue;
		}
		bool yes = true;
		for (int i = 1; i < n; ++i)
		{
			if(str[i-1] != 'W')
			{
				if(str[i] == 'W')
				{
					cout<<++x<<" "<<"i: "<<i<<" i am here\n";
					yes = false;
					break;
				}

				i++;
			}
			
		}



		if(yes)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
}