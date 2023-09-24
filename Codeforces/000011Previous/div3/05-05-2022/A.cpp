#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		if(a+b+c >= x+y)
		{
			if(a >= x && b >= y)
				cout<<"Yes\n";
			else if(a >= x && b+c >= y)
				cout<<"Yes\n";
			else if(a+c >= x && b >= y)
				cout<<"Yes\n";
			else
			{
				
				int for_cats = 0, for_dogs = 0;
				if(c >= x - a)
					for_dogs += x-a;
				c -= x-a;
				if(c > 0)
					for_cats+= c;
				if(for_cats >= b && for_dogs >= a)
					cout<<"Yes\n";
				else
				{
					cout<<"No\n";
				}

			}
		}
		else
		{
			cout<<"No\n";
		}
	}
}