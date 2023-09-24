#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case{
		int n,k;
		cin>>n>>k;
		vector<int>v(n);
		map<int,int>m;
		for(int& i : v)
		{
			 cin>>i;
			 m[i]++;
		}
		
		vector<int>res(n);
		//fill(res.begin(), res.end(), 0);
		bool yes = false;
		for(auto i : m)
		{
			if(i.second>=k){
				res[i.first] = 1;
				yes = true;
			}
			else
			{
				res[i.first] = 0;
			}
		}
		int l,r,mx = 0;
		for(int i = 0; i<n; i++)
		{
			int sum = 0;
			if(res[i]!=0)
			{
				int p = i,q;
				while(res[i++]!=0);
					q= i-1;
				if(q-p>mx)
				{
					mx = q-p;
					l = p;
					r = q;

				}
			}
		}

		if(yes)
			cout<<v[l]<<" "<<v[r]<<endl;
		else
			cout<<-1<<endl;
	}


}