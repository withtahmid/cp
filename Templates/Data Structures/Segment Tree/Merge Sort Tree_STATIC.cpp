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
