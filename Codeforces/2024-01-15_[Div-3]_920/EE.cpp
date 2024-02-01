/**
 *
 * Author: withtahmid
 * Created: 2024-01-15 20:33:29
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
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) { ((cout << a), ...); }
inline void println(const auto &...a) { print(a..., '\n'); }
inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
inline void read(deque<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void solve(const int case_no){
    int h, w, xa, ya, xb, yb;
    read(h, w, xa, ya, xb, yb);
    pii alice = {ya, ya}, bob = {yb, yb};
    if(xa > xb){
        println("Draw");
        return;
    }
    bool tern = true;
    while(xa < xb){
        if(tern){
            alice = {
                max(alice.first - 1, 1),
                min(alice.second + 1, w)
            };
            ++xa;
        }else{
            bob = {
                max(bob.first - 1, 1),
                min(bob.second + 1, w)
            };
            --xb;
        }
        tern = not tern;
    }
    tern = not tern;
    if(tern){
        if(alice.first <= bob.first and bob.second <= alice.second){
            println("Alice");
        }else{
            println("Draw");
        }
    }else{
        if(bob.first <= alice.first and alice.second <= bob.second){
            println("Bob");
        }else{
            println("Draw");
        }
    }
}
