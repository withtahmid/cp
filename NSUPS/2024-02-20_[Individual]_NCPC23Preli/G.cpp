/**
 *
 * Author: withtahmid
 * Created: 2024-02-20 16:58:09
 *
 **/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define local(...) 
#define debug(...)
#define dbg(...)
#endif
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto& a){cout<<a;}
inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
inline void print(const auto &...a) {((print(a)), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto& x){return(cin >> x) ? true : false;}
inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
inline string kes(int k){return("Case "+to_string(k)+": ");}
template <class T>inline T scan(){T t;read(t);return t;}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(const int& case_no);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}
void solve([[maybe_unused]] const int& case_no){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  auto get = [&]() {
    map<int, int> cnt;
    map<int, deque<int>> ind;
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i]];
      ind[a[i]].push_back(i);
    }
    int l = -1, last = -1;
    for (int i = 0; i < n; ++i) {
      int idx = INT_MIN;
      if (!ind[b[i]].empty()) {
        idx = ind[b[i]].front();
        ind[b[i]].pop_front();
      }
      if (idx < last) {
        l = i;
        break;
      }
      last = idx;
    }
    if (l == -1) {
      return 0;
    }

    auto check = [&](int L, int R) {
      vector<int> cur;
      for (int i = 0; i < n; ++i) {
        if (i >= L && i <= R) continue;
        cur.push_back(b[i]);
      }
      int j = 0;
      int m = (int) cur.size();
      for (int i = 0; i < n; ++i) {
        if (j < m && a[i] == cur[j]) {
          ++j;
        }
      }
      return j == m;
    };
    int ans = INT_MAX;
    for (int i = l; i < n; ++i) {
      int L = l, R = i;
      auto ret = check(L, R);
      if (ret) {
        ans = min(ans, R - L + 1);
      }
      // cout << L << " " << R << " " << check(L, R) << '\n';
    }
    for (int i = 0; i <= l; ++i) {
      int L = i, R = l;
      auto ret = check(L, R);
      if (ret) {
        ans = min(ans, R - L + 1);
      }
    }
    for (int i = 0; i <= l; ++i) {
      int L = i, R = l;
      auto ret = check(L, R);
      if (ret) {
        ans = min(ans, R - L + 1);
      }
      // cout << L << " " << R << '\n';
    }
    return ans;
  };

  int ans = get();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  ans = min(ans, get());
  cout << "Case " << case_no << ": " << ans << '\n';
}
