#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

const int N = 25, offset = 12;

const int x[] = { -1, +1, +0, +0 };
const int y[] = { +0, +0, +1, -1 };

int grid[N][N];

string s;

void fn(int i, int j){
    if(grid[i][j] != 0){
        return;
    }
    else if(i < offset - 10 or i > offset + 10  or j < offset - 10 or j > offset + 10){
        return;
    }
    grid[i][j] = 1;
    for(int p = 0; p < 4; ++p){
        if(s[p] == '1'){
            fn(i + x[p], j + y[p]);
        }
    }
}


void solve(const int& tc){
    memset(grid, 0, sizeof(grid));
    cin >> s;
    fn(offset, offset);
    int64_t res = 0LL;
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j){
        res += grid[i][j];
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
