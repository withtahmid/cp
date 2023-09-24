#include<bits/stdc++.h>
#include<debug.h>
using namespace std;

long double p[3000];

long double dp[3001][1501];



long double solve(int i,int tail_count){

    if(dp[i][tail_count]!=2){
        return dp[i][tail_count];
    }
    long double ans=0;

    if(i==1 && tail_count==0)return p[1];

    else if(i==1 && tail_count>0)return (long double)1;

    else if(tail_count==0)ans= p[i]*solve(i-1,tail_count);
    else ans= (p[i]*solve(i-1,tail_count)+(1-p[i])*solve(i-1,tail_count-1));

    dp[i][tail_count]=ans;
    return ans;
}


int main(){
    io();
    for(int i=0;i<3000;i++){
        for(int j=0;j<1500;j++){
            dp[i][j]=2;
        }
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    
    cout<<solve(n,(n-1)/2);
    return 0;
}