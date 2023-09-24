#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v1(n);
	vector<int> v2(n);
	set<int> s1;
	set<int> s2;
	for(int& i:v1){
		cin>>i;
		s1.insert(i);
	}
	
	for(int& i:v2)
	{
		cin>>i;
		s2.insert(i);
	}

	int countSame = 0;
	int countDifferent = 0;

	for(int i=0; i<n; i++)
	{
		if(v1[i] == v2[i]) countSame++;
		else
		{
			if(s1.find(v1[i]) != s1.end() && s2.find(v1[i])  != s2.end() && v1[i] != v2[i])
				countDifferent++;
		}
	}
	cout<<countSame<<"\n"<<countDifferent<<endl;

}