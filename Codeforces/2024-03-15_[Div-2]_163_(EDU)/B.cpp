#include<bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define dbg(...)
#endif

bool read(auto & ...x) {return (((cin >> x) ? 1 : 0) && ...);}
void print(const auto & ...x) {((cout << x), ...);}
void println(const auto & ...x) {print(x..., '\n');}

void solve(const int & tc) {
    int n;
    read(n);
    vector<int>v(n);
    for (auto& i : v) {
        read(i);
    }
    int prev = v.back();
    for (int i = n - 2; i >= 0; --i) {
        if (v[i] <= prev) {
            prev = v[i];
        } else {
            if (v[i] < 10) {
                return println("NO");
            }
            int a = v[i] / 10, b = v[i] % 10;
            if (a > b or b > prev) {
                return println("NO");
            }
            prev = a;
        }
    }
    println("YES");
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