/**
 *
 * Author: withtahmid
 * Created: 2023-09-19 12:53:36
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
#define rall(v) v.rend(), v.rbegin()
#define sp(n) setprecision(n)
#define len(v) ((int) v.size())
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){print(args..., '\n');}
inline void print(vector<auto>& v){for(auto& i:v){cout << i << ' ';}cout << endl;}
inline void print(vector<auto>& v, char sep){for(auto& i:v){cout << i << sep;}cout << endl;}
void solve(int);
void before_testcase();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = not true;
    before_testcase();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif

}
void before_testcase(){}
void solve([[maybe_unused]] const int case_no){
    
    int  n, m, q;
    cin >> n >> m >> q;
    map<int, vector<ll>>mp;
    for(int i = 0; i < n; ++i){
        ll p, id;
        cin >> p >> id;
        mp[(int)(id) -1].push_back(p);
    }
    
    vector<ll> discount(m);
    for(auto&i : discount){
        cin >> i;
    }
    
    int for_free = 0;
    vector<ll>book;
    
    for(int i = 0; i < m; ++i){
        
        vector<ll>& v = mp[i];
        sort(all(v));
        
        for(int j = 0; j < v.size(); ++j){
            if(v[j] > discount[i]){
                v[j] -= discount[i];
                break;
            }
            discount[i] -= v[j];
            v[j] = 0;
        }

        for(int j = 0; j < v.size(); ++j){
            if(v[j] == 0){
                ++for_free;
            }
            else{
                book.push_back(v[j]);
            }
        }

    }

    sort(all(book));

    for(int i =  1; i < book.size(); ++i){
        book[i] += book[i-1];
    }
 
    while(q--){
        ll x;
        cin >> x;
        cout << (int)(upper_bound(all(book), x) - book.begin())  + for_free<< endl;
    }

}
