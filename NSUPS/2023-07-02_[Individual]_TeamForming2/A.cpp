/**
 * 
 * Author: withtahmid
 * Created: 2023-07-02 15:02:57
 * 
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h> 
#else
#define debug(...)
#define dbg(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define len(v) ((int) v.size())
#define vec vector
#define forn(n) for(int i = 0; i < n; ++i)
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline bool in(auto&...args) { return (((cin >> args) ? true : false) && ...);}
inline void in(vector<auto>&v){for(auto&i:v){in(i);}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T maxx(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T minn(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
vector<pii>ranges_pair;
bool isWithinSameRange(int x, int y, int n) {
    --n;
    auto binarySearchLeft = [&](int target) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (ranges_pair[mid].first >= target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    };

    auto binarySearchRight = [&](int target, int leftIndex) {
        int left = leftIndex;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (ranges_pair[mid].second >= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return right;
    };

    int leftIndex = binarySearchLeft(x);

    if (leftIndex < 0) {
        return false;
    }

    int rightIndex = binarySearchRight(y, leftIndex);

    if (rightIndex == n) {
        return false;
    }

    for (int i = leftIndex; i <= rightIndex; ++i) {
        if (ranges_pair[i].first <= x && x <= ranges_pair[i].second && ranges_pair[i].first <= y && y <= ranges_pair[i].second) {
            return true;
        }
    }
    return false;
}


void solve(int case_no){
    int n, m, q;
    cin >> n >> m >> q;
    vi l(m), r(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < m; ++i){
        ranges_pair.pb({l[i], r[i]});
    }
    sort(ranges_pair.begin(), ranges_pair.end(), [](const auto& a, const auto& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << (isWithinSameRange(u, v, m) ? "YES" : "NO") << endl;
    }
}