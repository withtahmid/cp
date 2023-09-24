#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v,a,b,c;
	cin>>v>>a>>b>>c;
	int total = a+b+c;
	int last  = v%total;
	if(last<a)
		cout<<"F"<<endl;
	else if(last<a+b)
		cout<<"M"<<endl;
	else
		cout<<"T"<<endl;
}