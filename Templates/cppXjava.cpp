typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>
#include<debug.h>
using namespace std;
typedef struct {void print(const auto& a){cout<<a;}
void print(const auto &...a) {((print(a)), ...);}
void println(const auto &...a) {print(a..., '\n');}}PPP;
typedef struct {PPP out;}QQQ;QQQ System;
typedef struct{
auto nextInt(){int f; cin >> f;return f;}
auto nextChar(){char f; cin >> f;return f;}
auto nextLong(){ll f; cin >> f;return f;}
auto nextDouble(){ld f; cin >> f;return f;}
auto nextLine(){string f; cin >> f;return f;}
}SQA; SQA sc;
class Main{
    public: static void mian(string args){
        System.out.println(sc.nextInt());
    }
};

int main(){
	 dbg(__init__());
	 Main OS;
	 int t = sc.nextInt();
	 while(t--){
	 	OS.mian("hi main function");
	 }
	 dbg(__elapsed__());
}