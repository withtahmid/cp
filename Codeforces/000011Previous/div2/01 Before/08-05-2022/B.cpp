#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)

int main()
{
	test_case{

		int n;
		cin>>n;
		string str;
		cin>>str;
		vector<int>v;

		for (int i = 0; i < n;)
		{
			int count = 0;
			char sub = str[i];
			while(str[i++] == sub && i<n)
				count++;
			v.push_back(count);	
		}

		if(v.size() == 1)
		{
			cout<<0<<endl;
			continue;
		}

		int count = 0;
		
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i]&1)
			{
				v[i]++;
				if(i<v.size()){
					v[i+1]--;
				}
				count++;
			}
		}
		
		cout<<count<<endl;
	}
}