#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define dbg(...)
#endif

bool read(auto &...x) { return (((cin >> x) ? 1 : 0) && ...); }
void print(const auto &...x) {((cout << x), ...); }
void println(const auto &...x) { print(x..., '\n'); }

void solve(const int& tc){
	int n;
	read(n);
	
	if(n & 1){
		return println("NO");
	}
	println("YES");
	for(int i = 0; i < n / 2; ++i){
		print("ABB");
	}
	println();
}
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		solve(i);
	}
}