#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case{
		int l1, r1, l2, r2;
		cin>>l1>>r1>>l2>>r2;
		int n = 55; 

		vector<int>v(n);
		fill(v.begin(), v.end(),0);
		for(int i = l1; i <= r1; i++)
		{
			v[i]++;
		}
		for(int i = l2; i <= r2; i++)
		{
			v[i]++;
		}
		bool found  = false;
		int common;
		for(int i=0; i<n; i++)
		{
			if(v[i]>1)
			{
				common = i;
				found = true;
				break;
			}
		}
		if(found)
		{
			cout << common << endl;
		}
		else
		{
			cout<< l1+l2<<endl;
		}
	}
}