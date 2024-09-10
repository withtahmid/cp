#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define local(...) do{ __VA_ARGS__ ;} while(0);
#define debug(...) cerr << "\nLine " << __LINE__ <<": [ " << #__VA_ARGS__ << " ] --> "; __dbg(__VA_ARGS__); cerr << "\n";

#define LINE "[ LINE: " + to_string(__LINE__) + " ] -> "

auto starttime = chrono::steady_clock::now();

string ok(){time_t Time; time(&Time);return ctime(&Time);}
string bye(){cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond";return "";}
string kes(int case_no){return string(case_no > 1 ? "\n" : "") + string("---- Case ") + to_string(case_no) + string(" ---------\n");}

inline void __dbg(){}
inline void __dbg(const bool& x){cerr << (x ? "true" : "false");}
inline void __dbg(const auto& x){cerr << x;}

inline void __dbg(const pair<auto, auto>& p){
 // __dbg("{ ", p.first, ", ", p.second, " }");
 cerr << "{" << p.first << " " << p.second << " }";
}
inline void __dbg(const vector<auto>& v){__dbg("[ ");for(const auto& i : v){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(stack<auto> stk){ __dbg("[ "); while(not stk.empty()){__dbg(stk.top());__dbg(" ");stk.pop();}__dbg("]");}
inline void __dbg(queue<auto> q){__dbg("[ ");while(not q.empty()){__dbg(q.front());__dbg(" ");q.pop();}__dbg("]");}
inline void __dbg(const deque<auto>& dq){ __dbg("[ ");for(const auto& i : dq){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(const set<auto>& st){ __dbg("[ ");for(const auto& i : st){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(const multiset<auto>& st){__dbg("[ ");for(const auto& i : st){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(const tree<auto, null_type, less<auto>, rb_tree_tag, tree_order_statistics_node_update>& s){__dbg("[ ");for(const auto& i : s){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(const tree<auto, null_type, less_equal<auto>, rb_tree_tag, tree_order_statistics_node_update>& s){__dbg("[ ");for(const auto& i : s){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(const tree<auto, null_type, greater<auto>, rb_tree_tag, tree_order_statistics_node_update>& s){__dbg("[ ");for(const auto& i : s){__dbg(i);__dbg(" ");}__dbg("]");}
inline void __dbg(const map<auto, auto>& mp){__dbg("[ "); for(const auto& [key, value] : mp){__dbg("{ "); __dbg(key); __dbg(" => "); __dbg(value);__dbg(" }");}__dbg("]");}

inline string binary4(uint16_t _decimal) { return bitset<4>(_decimal).to_string(); }
inline string binary8(uint16_t _decimal) { return bitset<8>(_decimal).to_string(); }
inline string binary16(uint16_t _decimal) { return bitset<16>(_decimal).to_string(); }
inline string binary32(uint32_t _decimal) { return bitset<32>(_decimal).to_string(); }
inline string binary64(uint64_t _decimal) { return bitset<64>(_decimal).to_string(); }
inline string binary_fit(uint64_t _decimal) {
  string bin = bitset<64>(_decimal).to_string();
  bin.erase(0, min<int>(bin.find_first_not_of('0'), (int)bin.length() - 1));
  return bin;
}

char dbgsep = ' ';

inline void dbg(){cerr << '\n';}

template<typename Type, typename... Args> 
inline void dbg(Type value, Args... args) { __dbg(value); __dbg(dbgsep); dbg(args...); }
