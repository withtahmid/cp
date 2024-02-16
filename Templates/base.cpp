#include<bits/stdc++.h>
using namespace std;
int main(){
	int pip;
	cin >> pip;
	while(pip--){
		int lol;
		string hello;
		cin >> lol >> hello;
		set<char>st;
		int ballooooonnn = 0;
		for(int i = 0; i < lol; ++i){
			ballooooonnn += 1 + (st.find(hello[i]) == st.end());
			st.insert(hello[i]);
		}
		cout << ballooooonnn << '\n';
	}
}