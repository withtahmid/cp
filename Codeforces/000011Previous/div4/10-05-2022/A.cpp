#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case{
		string str;
		cin>>str;
		int s1 = (str[0] - '0') + (str[1]-'0') + (str[2]-'0');
		int s2 = (str[3] - '0') + (str[4]-'0') + (str[5]-'0');
		s1 == s2 ? cout<<"YES\n" : cout<<"NO\n";
	}
} 