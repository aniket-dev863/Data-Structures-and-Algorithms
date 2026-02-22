// House robber 5 with contriants .
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int n ; 
int nums[100100],color[100100];
int dp[100100][2];
bool vis[100100][2];
int rec(int level,int prev_taken,int prev_color){
    // prunning 
    // base Case
    if(level == n){
        return 0;
    }
    // cache check
    if(vis[level][prev_taken]){
        return dp[level][prev_taken] ;
    }
    // transition
    vis[level][prev_taken]=true;
    int take = INT_MIN ; 
    if(prev_taken==0 || prev_color!=color[level]){
        take = nums[level]+rec(level+1,1,color[level]);
    }
    int notTake = INT_MIN ; 
    notTake = rec(level+1,0,-1);
    // save and return 
    return dp[level][prev_taken] = max(take,notTake);
}
void solve(){
    cin>>n;
    for(int i =0 ;i<n;i++){
        cin>>nums[i];
    }
    for(int i =0 ;i<n;i++){
        cin>>color[i];
    }
    memset(vis,false,sizeof(vis));
    cout<<rec(0,0,-1)<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0 ;
}


/**
 * This is the solution to house robber - 5 . 
 * mentioned on the leetcode appeared in the contest few days ago .
 */