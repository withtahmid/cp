/**
 * 
 * Author: withtahmid
 * Created: 27-01-2023 20:32:23
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...) 
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define sizeof(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(int case_no){
    int n;
    cin >> n;
    map<int, int>mp;
    for(int i = 0; i < n; ++i){
        int inpt;
        cin >> inpt;
        ++mp[inpt];
    }
    vector<map<int,int>>vec_map;
    map<int, int>temp_map;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it != mp.begin()){
            auto temp = it;
            --temp;
            if((it->first - 1)  != temp->first){
                vec_map.push_back(temp_map);
                temp_map.clear();
            }
        }
       
        temp_map.insert(*it);

        auto temp = it;
        temp++;
        if(temp == mp.end()){
            vec_map.push_back(temp_map);
            temp_map.clear();
        }
    }
    for(auto i : vec_map){
        debug(i);
    }
    int res = 0;
    // debug(sizeof(m));
    for(auto m : vec_map){
        while(m.size()){
            vector<int>v;
            int previous = m.begin() -> first;
            for(auto& i : m){
                --i.second;
                if(i.second < 1){
                    v.pb(i.first);
                }
            }
            for(auto i : v){
                m.erase(i);
            }
            ++res;
            // debug(sizeof(m));
        }
    }

    cout << res << endl;
}
