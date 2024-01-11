/**
 *
 * Author: withtahmid
 * Created: 2023-10-13 15:57:51
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

bool subsetSum(vector<int> const &S, int n, int a, int b, int c, auto &lookup)
{
    
    if (a == 0 && b == 0 && c == 0) {
        return true;
    } 
  
    if (n < 0) {
        return false;
    }
 
    string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) +
                "|" + to_string(n);
 
    if (lookup.find(key) == lookup.end())
    {       
        bool A = false;
        if (a - S[n] >= 0) {
            A = subsetSum(S, n - 1, a - S[n], b, c, lookup);
        } 
        
        bool B = false;
        if (!A && (b - S[n] >= 0)) {
            B = subsetSum(S, n - 1, a, b - S[n], c, lookup);
        } 
       
        bool C = false;
        if ((!A && !B) && (c - S[n] >= 0)) {
            C = subsetSum(S, n - 1, a, b, c - S[n], lookup);
        } 
   
        lookup[key] = A || B || C;
    } 
  
    return lookup[key];
}
 

bool partition(vector<int> const &S)
{
    int n = S.size();
 
    int sum = accumulate(S.begin(), S.end(), 0);
    if (sum == 0) return true;   
    if (n < 3) {
        return false;
    }    
    unordered_map<string, bool> lookup;
 
    return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3, lookup);
}
 

void solve(const int case_no)
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto &x: v) cin >> x;

    ll sum = 0;
    vector <int> temp;
    for (int i = 0; i < n; ++i) {
        temp.push_back(v[i]);
        sum += v[i];
        if (sum % 3) {
            cout << 0 << endl;           
        }else{
            if (partition(temp)) {
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }

    
}