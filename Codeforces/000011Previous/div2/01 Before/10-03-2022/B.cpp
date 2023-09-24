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
		if(n>2 && n%2==0)
			cout<<"NO"<<endl;
		else if (n==2)
			cout<<"YES\n"<<1<<" "<<337<<endl;
		else if (n==3)
			cout<<"YES\n"<<31<<" "<<4<<" "<<159<<endl;
		else
		{
			cout<<"YES\n";
			for(int i=0;i<n-1;i++)
			{
				cout<<"337 1 ";
			}cout<<"337"<<endl;

		}	
	}
	return 0;
}