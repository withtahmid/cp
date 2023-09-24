#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		set<char> keys;
		string str;
		cin>>str;
		bool yes = true;
		for(int i=0; i<str.size(); i++)
		{
			if(str[i] == 'r' || str[i] == 'g' || str[i] == 'b'){
				keys.insert(str[i]);
			}
		else {

			if(keys.find(str[i]+32) == keys.end())
			{
				yes = false;
			}
		}

		}
		//cout<<endl;
		if(yes)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

}