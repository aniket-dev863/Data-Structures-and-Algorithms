// Again form 1 question to optimise the picking of the elements 
// Pick / not pick one 
/*
    Minimum number of ways required to pickup to c
*/
#include<vector>
#include<iostream>
#include<algorithm>
int dp[1001][1001];
using namespace std ;
int rec(int i , int Sum, int n, int x, int arr[]){
    // prunning
    if(Sum>x){
        return 1e9;
    } 
    // base case
    if(i==n){
        if(Sum==x)return 0;
        else return 1e9;
    }
    // cache check
    if(dp[i][Sum]!=-1){
        return dp[i][Sum];
    }
    // transition
    int ans = min(1+rec(i+1,Sum+arr[i],n,x,arr) , rec(i+1,Sum,n,x,arr));
    // save and return 
    return dp[i][Sum]=ans;
}
void solve(){
    int n , x ;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    int ans = (rec(0,0,n,x,arr)==1e9)?-1:rec(0,0,n,x,arr);
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}