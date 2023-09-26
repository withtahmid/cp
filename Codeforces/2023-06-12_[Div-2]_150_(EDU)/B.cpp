/**
 * 
 * Author: withtahmid
 * Created: 2023-06-12 20:33:10
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
#define all(v) (v.begin(),v.end())
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
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(int case_no){
    int n;
    cin >> n;
    vi v(n);
    cin >> v;

    bool sorted = true;
    for(int i = 1; i < n; ++i){
        if(v[i] < v[i-1]){
            sorted = false;
            break;
        }
    }
    if(sorted){
        forn(n){
            cout<<1;
        }cout<<endl;
        return;
    }

    int idx = 0;
    cout << 1;
    for(int i = 1; i < n; ++i){
        if(v[i] <  v[i-1]){
            break;
        }
        cout << 1;
        idx = max(idx, i);
    }
    dbg(v[idx]);
    for(int i = idx + 1; i < n; ++i){
        if(v[i] <= v[0]){
            int prev = v[i];
            for(int j = i; j < n; ++j){
                if(v[j] <= v[0] and v[j] >= prev){
                    prev = v[j];
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            cout<<endl;
            return;
        }
        if(v[i] >= v[idx]){
            dbg(i);
            int prev = v[i];
            
            for(int j = i; j < n; ++j){
                if(v[j] <= v[0]){
                    dbg(j);
                    prev = v[j];
                    for(int k = j; k < n; ++k){
                        if(v[k] <= v[0] and v[k] >= prev){
                            prev = v[k];
                            cout << 1;
                        }
                        else{
                            cout << 0;
                        }
                    }
                    cout << endl;
                    return;
                }

                if(v[j] >= prev){
                    prev = v[j];
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            cout<<endl;
            return;
        }
        else{
            cout << 0;
        }
    }
    cout << endl;

}