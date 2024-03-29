/**
 *
 * Author: withtahmid
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define local(...) 
#define debug(...)
#define dbg(...)
#endif
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef pair<int, int> pii;
void solve(const int& case_no);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}

void precompute(){}
void brutforce(){}

const int maxn = 30000 + 69;
vector<int>sgtree[maxn * 4];

void mergeNode(vector<int>&v, vector<int>& vl, vector<int>& vr){
    v.resize(vl.size() + vr.size());
    std::merge(vl.begin(), vl.end(), vr.begin(), vr.end(), v.begin());
}

int getResult(const vector<int>& v, int& k){
    return int(v.end() - upper_bound(v.begin(), v.end(), k));
}

void build(uint stIndex, uint left, uint right, vector<int>& v){
    if(left == right){
        sgtree[stIndex].push_back(v[left]);
        return;
    }
    const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
    build(lc, left, mid, v);
    build(rc, mid + 1, right, v);
    mergeNode(sgtree[stIndex], sgtree[lc], sgtree[rc]);
}

int query(uint stIndex, uint left, uint right, uint lo, uint hi, int k){
    if(left == lo and right == hi){
        return getResult(sgtree[stIndex], k);
    }
    const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
    if(hi <= mid){
        return query(lc, left, mid, lo, hi, k);
    }
    if(lo > mid){
        return query(rc, mid + 1, right, lo, hi, k);
    }
    int lRes = query(lc, left, mid, lo, mid, k);
    int rRes = query(rc, mid + 1, right, mid + 1, hi, k);
    return lRes + rRes;
}

/**
 * build(1, 0, n - 1, v);
 * query(1, 0, n - 1, l - 1, r - 1, k)
 * */ 



void solve([[maybe_unused]] const int& case_no){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
    	cin >> i;
    }
    build(1, 0, n - 1, v);
    int q;
    cin >> q;
    while(q--){
    	int l, r, k;
    	cin >> l >> r >> k;
    	cout << query(1, 0, n - 1, l - 1, r - 1, k) << "\n";
    }
}
