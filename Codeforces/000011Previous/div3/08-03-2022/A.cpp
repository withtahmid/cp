#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		char c;
		cin>>str;
		cin>>c;
		bool yes = false;
		for(int i=0; i<str.size(); i++)
		{
			if(i%2==0 && str[i] == c){
				yes = true;
				break;
			}
		}
		if(yes)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}