// find the number of ways to make sum=x using a subset or subsequence of the array
/**
 * Given a Array and size .
 * Output number of ways to make sum = x ;
 */
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std ;
int dp[1001][1001];
int rec(int i , int sum,int n , int x,int arr[]){
    //prunning 
    if(sum>x){
        return 0;
    }
    //base case
    if(i==n){
        if(sum==x)return 1;
        else return 0;
    }
    //cache check
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    //transition
    int ans  = rec(i+1,sum+arr[i],n,x,arr)+ rec(i+1,sum,n,x,arr);
    //save and return
    return dp[i][sum]=ans;
}
void Solve(){
    int n , sum ;
    cin>>n>>sum ;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,n,sum,arr)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0 ;
}