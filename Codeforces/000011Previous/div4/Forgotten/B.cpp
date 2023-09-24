#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<int,int>m;
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin>>temp;
			m[temp]++;
		}
		int num;
		bool yes = false;
		for(auto i : m)
		{
			if(i.second>=3)
			{
				num = i.first;
				yes = true;
				break;
			}
		}
		if(yes)
			cout<<num<<endl;
		else
			cout<<-1<<endl;

	}
}