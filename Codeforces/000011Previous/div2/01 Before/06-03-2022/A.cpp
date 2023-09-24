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
		for(int& i:v)
			cin>>i;
		int f_zero;
		int l_zero;

		bool yes = true;
		int count = 0;
		for(int i= 0; i<n; i++)
		{
			if(v[i]==0)
			{
				count++;

			}

		}
		if(count==0){
			cout<<0<<endl;
			cout<<"I am hjere"<<endl;
		}

		else{
			for(int i=0; i< v.size(); i++)
			{
				if(v[i] == 0)
					f_zero = i-1;
			}
			for(int i=v.size()-1; i>=0; i--)
			{
				if(v[i] == 0)
					l_zero = i+1;
			}


			cout<< l_zero - f_zero<<endl;

		}
		
	}

}