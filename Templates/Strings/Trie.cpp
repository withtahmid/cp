#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

struct TrieNode{
    int childs[26];
    TrieNode(){
        this -> clear();
    }
    void clear(){
        memset(childs, -1, sizeof(childs));
    }
    int& operator[](int i){
        return childs[i];
    }
};

class Trie{
private:
    int node_id = 0, N = 0;
    vector<int> prf_cnt, word_cnt;
    vector<TrieNode> to;
    Trie(){}
public:
    Trie(int n){
        this -> N = n, node_id = 0;
        prf_cnt = word_cnt = vector<int>(this->N, 0);
        to = vector<TrieNode>(this -> N);
    }
    void clear(){
        for(int i = 0; i <= node_id; ++i){
            prf_cnt[i] = word_cnt[i] = 0;
            to[i].clear();
        }
        node_id = 0;
    }
    void insert(const string& s){
        assert(int(s.size()) < N);
        int curr_node = 0;
        for(const char& c : s){
            if(to[curr_node][c - 'a'] == - 1){
                to[curr_node][c - 'a'] = ++node_id;
            }
            curr_node = to[curr_node][c - 'a'];
            ++prf_cnt[curr_node];
        }
        ++word_cnt[curr_node];
    }
    int prefix_count(const string& s){
        assert(int(s.size()) < N);
        int curr_node = 0;
        for(const char& c : s){
            if(to[curr_node][c - 'a'] == -1){
                return 0;
            }
            curr_node = to[curr_node][c - 'a'];
        }
        return prf_cnt[curr_node];
    }
};

void solve(const int& tc){
    Trie tr(12);
    tr.insert("apple");
    tr.insert("apply");
    dbg(tr.prefix_count("appl"));
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
