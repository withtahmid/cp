// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3, unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void run_case(int tc) {
  int n;
  cin >> n;
  vector<array<int, 26>> freq(n);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (auto x: s) {
      ++freq[i][x - 'a'];
    }
  }
  int q;
  cin >> q;
  cout << "Case " << tc << ":" << '\n';
  for (int i = 0; i < q; ++i) {
    string s;
    cin >> s;
    vector<int> f(26);
    for (auto x: s) ++f[x - 'a'];
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      bool good = true;
      for (int c = 0; c < 26; ++c) {
        if (freq[j][c]) {
          if (freq[j][c] > f[c]) good = false;
        }
      }
      cnt += good;
    }
    cout << cnt << '\n';
  }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        run_case(tc);
    }


  return 0;
}