#include<bits/stdc++.h>
using namespace std;
struct People
{
	int x;
	int y;
	char d;
};
bool compare(People a, People b)
{
	return a.x < b.x;
}
int main()
{
	int n;
	cin>>n;
	vector<People>people(n);

	for(People& i : people) 
		cin>>i.x>>i.y;

	string str;
	cin>>str;

	for (int i = 0; i < n; ++i)
		people[i].d = str[i];

	sort(people.begin(),people.end(),compare);

	bool yes = false;

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++ )
		{
			if((people[i].x < people[j].x) && (people[i].y == people[j].y) &&(people[i].d=='R' && people[j].d =='L'))
			{
					yes =true;
					break;
			}
			
		}
		if(yes)
			break;
	}
	if(yes)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


}