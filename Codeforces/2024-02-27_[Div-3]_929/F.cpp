/**
 *
 * Author: withtahmid
 * Created: 2024-02-27 20:29:55
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
typedef struct {
    int i = -1, j = -1, t = -1;
} Node;
void solve([[maybe_unused]] const int& case_no){
    int n, m;
    read(n, m);

    vector<vector<int>>v(n, vector<int>(m));
    read(v);
    dbg(v);
    vector<vector<int>>dist(n, vector<int>(m, -1));
    queue<Node>q;
    q.push(Node(0, 0, 0));
    dist[0][0] = 0;

    auto goDown = [&](Node node){
        int i = (node.i + node.t) % n;
        int j = node.j;
        if(v[(i + 1) % n][j] == 1 or v[(i + 2) % n][j] == 1){
            return false;
        }
        return true;
    };

    auto goRight = [&](Node node){
        int i = (node.i + node.t) % n;
        int j = node.j;
        if(j + 1 == m ){
            return false;
        }
        if(v[(i + 1) % n][j + 1] == 1){
            return false;
        }
        return true;
    };

    auto up = [&](Node node) -> pii{
        int i = node.i - 1;
        if(i < 0){
            i = n - 1;
        }
        return make_pair(i, node.j);
    };

    auto down = [&](Node node) -> pii{
        return make_pair((node.i + 1) % n, node.j);
    };

    auto right = [&](Node node) -> pii{
        return make_pair(node.i, node.j + 1);
    };

    while(not q.empty()){
        auto u = q.front();
        q.pop();
        auto [upi, upj] = up(u);
        if(dist[upi][upj] == -1){
            dist[upi][upj] = dist[u.i][u.j] + 1;
            q.push(Node(upi, upj, u.t + 1));
        }
        if(goDown(u)){
            auto[di, dj] = down(u);
            if(dist[di][dj] == -1){
                dist[di][dj] = dist[u.i][u.j] + 1;
                q.push(Node(di, dj, u.t + 1));
            }
        }
        if(goRight(u)){
            auto[ri, rj] = right(u);
            if(dist[ri][rj] == -1){
                dist[ri][rj] = dist[u.i][u.j] + 1;
                q.push(Node(ri, rj, u.t + 1));
            }
        }
    }
    println(dist[n - 1][m -1]);
    if(case_no == 6){
        for(auto i : dist){
            dbg(i);
        }
    }

}
