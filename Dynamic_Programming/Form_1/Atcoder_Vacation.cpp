// https://atcoder.jp/contests/dp/tasks/dp_c
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
int choices[100100][4],n;
int memo[100100][4];
int rec(int level,int prev){
    //prunning 
    //base case
    if(level==n){
        return 0;
    }
    //cache check
    if(memo[level][prev]!=-1){
        return memo[level][prev];
    }
    //transition
    int ans=-1e9;
    for(int i=1;i<=3;i++){
        if(i!=prev){
            ans=max(ans,choices[level][i]+rec(level+1,i));
        }
    }
    //save and return 
    return memo[level][prev]=ans ;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++){
            cin>>choices[i][j];
        }
    }
    memset(memo,-1,sizeof(memo));
    cout<<rec(0,0)<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}