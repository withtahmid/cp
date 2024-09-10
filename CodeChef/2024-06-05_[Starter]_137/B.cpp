#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

template<class T>
class SparseTable{
private:
    vector<vector<T>>st;
    function<T(T, T)> func;
    int n, lgn;
public:
    SparseTable(const vector<T>& v, const function<T(T, T)>& _func){
        this -> func = _func;
        this -> n = v.size();
        assert(n != 0);
        this -> lgn = __lg(v.size()) + 1;
        this -> st.resize(n, vector<T>(lgn));
        for(int i = 0; i < this -> n; ++i){
            this->st[i][0] = v[i];
        }
        for(int j = 1; j < lgn; ++j){
            for(int i = 0; i + (1 << j) - 1 < this->n; ++i){
                this->st[i][j] = this->func(this->st[i][j - 1], this->st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r){
        assert(0 <= l and r < this->n and l <= r);
        int lgr = __lg((r - l + 1));
        return (this->func(this->st[l][lgr], this->st[r - (1 << lgr) + 1][lgr]));
    }
};

/**
 * 
 * @SparseTable<int> st(v, [&](int a, int b){return min(a, b);});
 * @st.query(l, r) // 0 based
 * 
 * */

const int N = 2e5 + 69;
static int n, x[N], p[N];
void solve(const int& tc){

    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }

    vector<bool> left_pos(n, false), right_pos(n, false);
    
    for(int i = 1; i < n; ++i){
        left_pos[i] = (p[i - 1] >= abs(x[i - 1] - x[i]));
    }
    for(int i = n - 2; i >= 0; --i){
        right_pos[i] = (p[i + 1] >= abs(x[i + 1] - x[i]));
    }

    dbg(left_pos);
    dbg(right_pos);

    left_pos[0] = right_pos[n - 1] = true;

    SparseTable<bool> lt(left_pos, [&](bool a, bool b){return a & b;});
    SparseTable<bool> rt(right_pos, [&](bool a, bool b){return a & b;});

    for(int i = 0; i < n; ++i){

        auto rposl = i < (n - 1) ? lt.query(i + 1, n - 1) : true;
        auto rposr = i < (n - 1) ? rt.query(i, n - 2) : true;
        auto rok = (rposl || rposr);

        auto lposl = i > 1 ? lt.query(1, i - 1) : true;
        auto lposr = i > 1 ? rt.query(0, i - 2) : true;
        auto lok = (lposl || lposr);

        if(lok && rok){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
