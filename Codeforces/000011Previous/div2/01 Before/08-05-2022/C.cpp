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

		for (int i = 0; i < n; ++i)
		{
			int count = 0;
			char sub = str[i];

			while(str[i] == sub && i<n)
			{
				count++;
				i++;
			}
			
			v.push_back(count);
			i--;
		}
		vector<int> v2 = v;
		if(v.size() == 1)
		{
			cout<<0<<" "<<1<<endl;
			continue;
		}
		int count_ = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i]&1)
			{
				v[i]++;
				if(i<v.size()){
					v[i+1]--;
					//count++;
				}
				count_++;
			}
		}
		sort(v.begin(), v.end());
		int count2 = 0, sum = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			sum += v[i];
			count2++;
			if(sum<=count_)
				break;
		}
		
		cout<<count_<<" "<< v.size() - count2 <<endl;

	}
}