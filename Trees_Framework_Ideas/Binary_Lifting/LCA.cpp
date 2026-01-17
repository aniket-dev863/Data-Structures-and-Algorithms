/**
 * Lowest Common Ancestor of a tree using binary lifting .
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std ;
int MAXN=100100;
int LOG=20;
int n,q ;
vector<int> adj[100100];
int depth[100100];
int up[100100][20];
void DFS(int u , int p ,int d ){
    depth[u]=d;
    up[u][0]=p;
    for(auto &v:adj[u]){
        if(v!=p)DFS(v,u,d+1);
    }
}
void preCompLCA(){
    for(int j=1;j<LOG;j++){
        for(int i =1;i<=n;i++){
            if(up[i][j-1]!=-1){
                up[i][j]=up[up[i][j-1]][j-1];
            }else{
                up[i][j]=-1;
            }
        }
    }
}
int getLCA(int u ,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    // depth of u should be higher as it depends further .
    
    // bring both u and v at the same depth ;

    int diff=depth[u]-depth[v];
    for(int j =0;j<LOG;j++){
        if((diff>>j)&1){
            u=up[u][j];
            
        }
    }

    if(u==v){
        return u;
        // Here u is the LCA.
        // Its a Skewed Tree . 
    }
    
    //Find the first uncommon node its parent is the LCA .
    for(int j =LOG-1;j>=0;j--){
        if(up[v][j]!=up[u][j]){
            v=up[v][j];
            u=up[u][j];
        }
    }
    // Parent of the last uncommon node is LCA 
    return up[u][0] ; 
}
void Solve(){
    cin>>n>>q;
    for(int i =0;i<=n;i++)adj[i].clear();
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =0;i<=n;i++){
        for(int j=0;j<LOG;j++){
            up[i][j]=-1;
        }
    }
    DFS(1,-1,0);
    preCompLCA();
    for(int i=0;i<q;i++){
        int u ,v  ;
        cin>>u>>v ;
        cout<<getLCA(u,v)<<"\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0;
}