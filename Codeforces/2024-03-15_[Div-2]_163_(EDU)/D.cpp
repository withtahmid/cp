#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define dbg(...)
#endif
void run_case(const int& tc){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int>a(n * 2);
	for(int i = 0; i < (2 * n); ++i){
		scanf("%d", &a[i]);
	}
	map<int, int>left, right;
	for(int i = 0, j = n; i < n; ++i, ++j){
		++left[a[i]], ++right[a[j]];
	}

	map<int, int>left_2, right_2;
	for(auto[key, val]: left){
		if(val ==  2){
			left_2[key] = val;
		}
	}

	for(auto[key, val]: right){
		if(val ==  2){
			right_2[key] = val;
		}
	} 

	vector<int>l, r;

	while(int(l.size()) < (2 * k ) and int(left_2.size()) > 0 and int(right_2.size()) > 0){
		l.emplace_back(left_2.begin()->first);
		l.emplace_back(left_2.begin()->first);
		r.emplace_back(right_2.begin()->first);
		r.emplace_back(right_2.begin()->first);
		left_2.erase(left_2.begin()), right_2.erase(right_2.begin());
	}

	for(auto[key, v] : left){
		if(int(l.size()) == 2 * k){
			break;
		}
		if(v == 1){
			l.emplace_back(key), r.emplace_back(key);
		}
	}
	
	for(int i = 0; i < l.size(); ++i){
		printf("%d ", l[i]);
	}
	puts("");
	for(int i = 0; i < r.size(); ++i){
		printf("%d ", r[i]);
	}
	println()
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		run_case(i);
	}
}