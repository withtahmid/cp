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


constexpr int N = 1E6 + 5, M = 1E9 + 7;
int64_t fact[N];
void fn() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % M;
  }
}

int64_t bin_pow(int64_t b, int64_t e) {
  int64_t res = 1;
  while (e > 0) {
    if (e & 1) res = (res * b) % M;
    b = (b * b) % M;
    e >>= 1;
  }
  return res;
}


bool good(vector<string> &g, int k, int s) {
  int n = g.size();
  int m = g.front().size();

  for (int l = 0, r = 0; r < m; ++r) {
    
    while (r - l + 1 > k) {
      ++l;
    }
    if (r - l + 1 == k) {
      unordered_set<char> st;
      for (int x = 0; x < n; ++x) {
        for (int y = l; y <= r; ++y) {
          st.insert(g[x][y]);
        }
      }
      if (st.size() != s) return false;
    }
  }
  return true;

  // for(int col = 0; col < n - k + 1; ++col) {
  //   set<char> st;
  //   for (int j = i, x = 1; j < m && x <= k; ++j, ++x) {
  //     st.insert(g[i][j]);
  //     cout << g[i][j];
  //   }
  //   cout << '\n';
  //   if (st.size() != s) return false;
  // }
  // return true;
}

int ck(vector<pair<int, int>> &id, vector<string> &g, int s, int k, int i = 0) {
  if (i == id.size()) {
    // for (auto x : g) cout << x << '\n';
    // cout << '\n';
    // cout << good(g, k, s) << '\n';
    return good(g, k, s);
  }
  int ans = 0;
  for (int c = 0; c < s; ++c) {
    g[id[i].first][id[i].second] = char(c + 'A');
    ans += ck(id, g, s, k, i + 1);
  }
  return ans;

}

int brute(int s, int n, int m) {
  vector<pair<int, int>> id;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) id.emplace_back(i, j);

    int ans = 0;
  vector<string> g(n, string(m, '?'));
  ans += ck(id, g, s, s / n);
  return ans;

}

int64_t inv(int64_t n) {
  return bin_pow(n, M - 2) % M;
}
int64_t nPr(int64_t n, int64_t r) {
  auto nf = fact[n] % M;
  // auto rf = fact[r] % M;
  auto n_r = fact[n - r] % M;
  auto den = inv(n_r) % M;
  return (nf * den) % M;
}

void run_case(int tc) {
  int64_t s, n, m;
  cin >> s >> n >> m;

  auto ans = (fact[s] % M * bin_pow(fact[n] % M, m - (s / n)) % M) % M;
  cout << ans % M << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fn();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        run_case(tc);
    }


  return 0;
}