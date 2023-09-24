#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string str;
		cin>>str;
		bool yes = true;
		stack<char>stk;
		string temp = "";
		for(int i=0; i<str.size(); i++)
		{
			if(stk.empty())
			{
				temp+=str[i];
				stk.push(str[i]);
				continue;
			}
			if(stk.top() == str[i]){
				stk.push(str[i]);
				temp+=str[i];
			}
			else
			{
				if(temp.size()<2)
				{
					yes = false;
					break;
				}
				else
				{
					temp = "";
					while(!stk.empty())
						stk.pop();
				}
				stk.push(str[i]);
				temp+=str[i];
			}
		}
		if(temp.size()<2)
		{
			yes = false;
	
		}
		yes ? cout<<"YES\n" : cout<<"NO\n";
	}
}