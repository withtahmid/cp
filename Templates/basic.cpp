#include<bits/stdc++.h>
using namespace std;
void solve(){
	
	string s, t;
    cin >> s >> t;
    
    vector<int>to_remove(26);

    for(const auto& c : s){
        ++ to_remove[c - 'A'];
    }

    for(const auto& c : t){
        -- to_remove[c - 'A'];
    }

    vector<vector<int>>indx(26);
    
    for(int i = (int)(s.size()) - 1; i >= 0; --i){
        indx[s[i] - 'A'].push_back(i);
    }

    for(int i = 0; i < 26; ++i){
        for(int x = 0; x < to_remove[i]; ++x){
            indx[i].pop_back();
        }
    }

    vector<int>res_indx;
    for(auto& i : indx) for(auto& j : i){
		res_indx.push_back(j);
    }
    
    sort(res_indx.begin(), res_indx.end());

    string res = "";
    for(auto i : res_indx){
        res += s[i];
    }
    
    cout << (res == t ? "YES" : "NO") << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}