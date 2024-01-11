/**
 *
 * Author: withtahmid
 * Created: 2023-12-13 20:10:36
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
void solve(const int case_no){
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    int cnt_0 = count(all(str), '0');
    int cnt_1 = count(all(str), '1');
    
    if(cnt_0 != cnt_1){
        cout << -1 << endl;
        return; 
    }

    vector <int> z;
    deque <char> q;

    for(auto i : str){
        q.pb(i);
    }

    int d = 0;

    while(not q.empty()){
        if(q.front() == q.back()){
            if(q.front() == '0'){
                q.push_back('0');
                q.push_back('1');
                z.push_back(n-d);
            }
            else{
                q.push_front('1');
                q.push_front('0');
                z.push_back(d);

            }
            n += 2;
        }
        while(not q.empty() and q.front() != q.back()){
            q.pop_front();
            q.pop_back();
            ++d;
        }
    }
    
    cout << len(z) << endl;
    for(auto i : z){
        cout << i << " "; 
    }
    cout << endl;



}
