/**
 *
 * Author: withtahmid
 * Created: 2023-10-16 01:07:04
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
void precompute(){}

const int maxn = (4 * 1e5) + 10;

vector<int>graph[maxn];

void solve(const int case_no){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        graph[i].clear();
    }
    
    set<int>st;
    st.insert(n);
    
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        st.insert(i);
    }
    
    set<int>next;

    
    for(int i = 1; i <= n; ++i){
        if(len(graph[i]) == 1){
            next.insert(i);
            st.erase(i);
        }
    }

    auto isleaf = [&](int x){
        int cnt = 0;
        for(auto i : graph[x]){
            if(st.find(i) != st.end()){
                ++cnt;
            }
        }
        return (bool) cnt == 1;
    };

    int itr = k - 1;
    while(len(st) and itr --){
        dbg(st, next);
        auto temp = next;
        next.clear();
        for(auto& i : temp){
            for(auto j : graph[i]){
                if(st.find(j) != st.end() and not isleaf(j)){
                    next.insert(j);
                    st.erase(j);
                }
            }
        }
    }
    cout << len(st) << endl;
}
