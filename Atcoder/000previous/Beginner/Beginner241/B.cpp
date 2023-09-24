#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	map<int,int> mp1;
	map<int,int>mp2;
	bool yes = true;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		mp1[temp]++;
	}

	for (int i = 0; i < m; ++i)
	{
		int temp;
		cin>>temp;
		mp1[temp]--;
		if(mp1[temp]== 0)
		{
			yes = false;
		}
	}

	if(yes)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	
	return 0;
}