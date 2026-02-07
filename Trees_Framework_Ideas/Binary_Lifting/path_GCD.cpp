#include<vector>
#include<iostream>
#include<numeric>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int n;
int LOG; 
vector<vector<int>>adj;
vector<vector<int>>up;
vector<vector<ll>>dp;
vector<int>dpt;
vector<int>val; 
void init(){
    cin>>n;
    LOG=1;
    val.assign(n+1,{});
    adj.assign(n+1,{});
    dpt.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    while((1<<LOG)<=n)LOG++;
    for(int i =0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    up.assign(n+1,vector<int>(LOG,-1));
    dp.assign(n+1,vector<ll>(LOG,-1));
}
void dfs(int node ,int par,int depth){
    up[node][0]=par;
    dpt[node]=depth;
    dp[node][0]=val[node];
    for(auto&child:adj[node]){
        if(child!=par){
            dfs(child,node,depth+1);
        }
    }
}
void build(){
    for(int j =1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            if(up[i][j-1]!=-1){
                up[i][j]=up[up[i][j-1]][j-1];
                dp[i][j]=__gcd(dp[i][j-1],dp[dp[i][j-1]][j-1]);
            }
            else{
                up[i][j]=-1;
                dp[i][j]=std::gcd(dp[i][j-1], dp[dp[i][j-1]][j-1]);
            }
        }
    }
}
pair<ll,int>lift(int u ,int diff){
    ll g =0 ;
    if(diff==0)return {g,u};
    for(int j=LOG;j>=0;j--){
        if((diff<<j)&&1){
            u=up[u][j];
            g=std::gcd(g,dp[u][j]);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}