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
class item{
public:
    int cnt;
    string parent;
    item(){}
    item(int a, string b){
        cnt = a;
        parent = b;
    }
};
string min(const string& str1, const string& str2) {
    if (str1.empty() || str2.empty()){
        return str1.empty() ? str2 : str1;
    }

    string smallestStr = str1;
    smallestStr.resize(min(str1.size(), str2.size()));

    if (str2.compare(0, smallestStr.size(), smallestStr) < 0){
        smallestStr = str2;
    }

    return smallestStr;
}
void solve(int case_no){
    int n;
    cin >> n;
    string str;
    map<string, string>mp;
    map<string, int> freq;
    for(int i = 0; i < n; ++i){
        cin >> str;
        ++freq[str];
        for(int i = 1; i <= len(str); ++i){
            string tempstr = str.substr(0, i);
            auto temp = mp.find(tempstr);
            if(temp == mp.end()){
                mp[tempstr] = str;
            }else{

                mp[tempstr] = min(mp[tempstr], str);
            }
        }
    }



    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i){
        string str;
        cin >> str;
        if(mp.find(str) == mp.end()){
            cout << "Case " << i <<": -1\n";
        }else{
            cout << "Case " << i <<": " << mp[str] << " " <<  freq[mp[str]] << endl;
        }
    }
}