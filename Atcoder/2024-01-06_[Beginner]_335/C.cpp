/**
 *
 * Author: withtahmid
 * Created: 2024-01-06 17:58:21
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
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
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
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
void solve(const int case_no){
    int n, q;
    cin >> n >> q;
    vector<pii>initial(n);
    for(int i = 0; i < n; ++i){
        initial[i] = make_pair(i +1, 0);
    }
    auto dir = [](char c){
        if(c == 'R'){
            return make_pair(+1, +0 );
        }
        else if(c == 'L'){
            return make_pair(-1, +0 );
        }
        else if(c == 'U'){
            return make_pair(+0, +1 );
        }
        else{
            return make_pair( +0, -1 );
        }
    };
    deque<pii>moves;
    while(q--){
        int mode;
        cin >> mode;
        if(mode == 2){
            int p;
            cin >> p;
            if(p <= len(moves)){
                dbg(p, moves);
                cout << moves[p-1].first << " " << moves[p-1].second << endl;
            }
            else{
                p -= len(moves);
                cout << initial[p-1].first << " " << initial[p-1].second << endl;
            }
            continue;
        }
        cin.ignore();
        char c;
        cin >> c;
        pii d = dir(c);
        pii head;
        if(len(moves) == 0){
            head = initial[0];
        }
        else{
             head = moves.front();
        }

        d.first += head.first;
        d.second += head.second;
        if(c== 'L'){
            dbg(head, d);
        }
        moves.push_front(d);
    }
}
