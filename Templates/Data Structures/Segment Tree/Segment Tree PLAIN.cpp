
const int maxn = 2e5;
int64_t sgtree[maxn << 2];

int64_t mergeNode(int64_t& LC, int64_t& RC){
	return LC + RC;
}

void build(int indx, int left, int right, vector<int>& v){
	if(left == right){
		sgtree[indx] = v[left]; // assignig leaf
		return;
	}
	int mid = (left + right) / 2; 
	int lc = indx * 2, rc = indx * 2 + 1;
	build(lc, left, mid, v);
	build(rc, mid + 1, right, v);
	sgtree[indx] = mergeNode(sgtree[lc], sgtree[rc]);
}

int64_t query(int indx, int left, int right, int ql, int qr){
	if(left == ql and right == qr){
		return sgtree[indx];
	}

	int mid = (left + right) / 2; 
	int lc = indx * 2, rc = indx * 2 + 1;
	if(qr <= mid){
		return query(lc, left, mid, ql, qr);
	}
	if(ql > mid){
		return query(rc, mid + 1, right, ql, qr);
	}
	int64_t lRes = query(lc, left, mid, ql, mid);
	int64_t rRes = query(rc, mid + 1, right, mid + 1, qr);
	
	return mergeNode(lRes, rRes);
}

void update(int indx, int left, int right, int i, int val){
	if(left == right){
		sgtree[indx] = val;
		return;
	}
	int mid = (left + right) / 2; 
	int lc = indx * 2, rc = indx * 2 + 1;
	if(i <= mid){
		update(lc, left, mid, i, val);
	}
	if(i > mid){
		update(rc, mid + 1, right, i, val);
	}
	sgtree[indx] = mergeNode(sgtree[lc], sgtree[rc]);
}