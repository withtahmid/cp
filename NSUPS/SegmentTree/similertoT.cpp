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
	std::vector<int> v(n);
	for(auto& i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end());
	dbg(v);
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
	int t = 1;
	// cin >> t;
	for(int i = 1; i <= t; ++i){
		solve(i);
	}
	dbg(__elapsed__());
}