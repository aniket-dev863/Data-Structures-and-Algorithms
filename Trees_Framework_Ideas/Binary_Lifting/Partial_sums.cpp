#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std ;
#define int long long 
/**
 * Global Variable Declarations.
 */
int n,q;
vector<vector<int>>g;
vector<vector<int>>up;
vector<int>dep;
vector<int>psums;

/**
 *Precomputation for Binary Lifting . 
 */
void PreCompute(){
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            if(up[i][j-1]!=0){
                up[i][j]=up[up[i][j-1]][j-1];
            }
            else{
                up[i][j]=0;
            }
        }
    }
}
/**
 * Add +x to v and then parent of v ie u , unitl you reach root . 
 */
void addAbove(int u, int p){
    for(auto &v:g[u]){
        if(v!=p){
            addAbove(v,u);
            psums[u]+=psums[v];
        }
    }
    //psums[p]+=psums[u];
    //above version also can be used both are correct //
}
/**
 * getLCA:Lowest Common Ancestors of two nodes 
 */
int getLCA(int u , int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    int diff=dep[u]-dep[v];
    for(int j=20;j>=0;j--){
        if((diff>>j)&1){
            u=up[u][j];
        }
    }
    if(u==v)return u;
    for(int j=20;j>=0;j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}
/**
 * Normal DFS Function
 */
void dfs(int u,int p,int d){
    up[u][0]=p;
    dep[u]=d;
    for(auto &v:g[u]){
        if(v!=p)dfs(v,u,d+1);
    }
}
/**
 * AddX : Add x to the shortest path between u and v .
 */
void AddX(int u, int v,int x){
    if(u==v){
        if(up[u][0]!=0){
            psums[up[u][0]]-=x;
        }
        psums[v]+=x;
        return;
    }
    psums[v]+=x;
    psums[u]+=x;
    int lca=getLCA(u,v);
    psums[lca]-=x;
    if(up[lca][0]!=0){
        psums[up[lca][0]]-=x;
    }
}
/**
 * Solve function
 */
void Solve(){
    cin>>n;
    g.assign(n+1,{});
    up.assign(n+1,vector<int>(21,0));
    dep.assign(n+1,{});
    psums.assign(n+1,0);
    for(int i =0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    PreCompute();
    cin>>q;
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        AddX(x,y,z);
    }
    addAbove(1,0);
    for(int i=1;i<=n;i++){
        cout<<psums[i]<<" ";
    }
    cout<<"\n";
}
/**
 * Main 
 */
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ts;cin>>ts;
    while(ts--)Solve();
    return 0;
}
