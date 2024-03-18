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

vector<int> x_dir = {  0, -1,  0, +1 };
vector<int> y_dir = { -1,  0, +1,  0 };

void solve(const int & tc) {
	int n;
	read(n);
	vector<string>v(2);
	read(v[0]), read(v[1]);


	vector<vector<bool>>vis(2, vector<bool>(n));
	queue<pair<int, int>>q;
	q.push({0, 0});

	vis[0][0] = true;

	auto inside = [&](int x, int y) -> bool{
		return bool(0 <= x and x < 2 and 0 <= y and y < n);
	};
	
	while(not q.empty()){
		auto [i, j] = q.front();
		q.pop();
		for(int d = 0; d < 4; ++d){
			int x = x_dir[d] + i, y = y_dir[d] + j;
			if(inside(x, y)){
				y += v[x][y] == '>' ? +1 : -1;
				if(not vis[x][y]){
					vis[x][y] = true;
					q.push({x, y});
				}
			}
		}
	}
	println(vis[1][n - 1] ? "YES" : "NO");
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
}