/**
 * Prefix Sums on Trees using  binary Lifting and LCA 
 * Idea 
 *      Every Node Stores sum sum of Distances from that node to root node .
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std ;
vector<pair<int,int>> g[100100];
int pref[100100];
int n,q; 
int up[100100][20] ;     // to cache the value of parents using Binary Lifting 
int dep[100100];        // To cache the values of the Depth 

/**
 * Depth First Search 
 * 
 * Prefix Arr pref stores the sum from root to current node .
 */

void DFS(int u,int p,int d,int sum){
    dep[u]=d;
    up[u][0]=p;
    pref[u]=sum;
    for(auto [v,w]:g[u]){
        if(v!=p){
            DFS(v,u,d+1,sum+w);
        }
    }
}

void Precompute(){
    /**
     * Precompute the Binary Lifting paths .
     */
}

/**
 * Lowest Commonn ancestor of two nodes 
 * Refer to LCA Code . 
 */
int getLCA(int x ,int y ){
    /**
     * Get The Lca of two paths using the Binary Lifitng paths .
     */

}


void Solve(){
    cin>>n;
    for(int i =0;i<=n;i++)g[i].clear();
    for(int j =0 ;j<20;j++){
        for(int i =0;i<=n;i++){
            up[i][j]=-1;   // Initialise .
        }
    }
    for(int i =0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    DFS(1,-1,0,0);
    Precompute();

    cin>>q; // number of queries 
    while(q--){
        int x,y;cin>>x>>y;
        int lca = getLCA(x,y) ;
        /**
         * Ans : sum of path between x and y .
         */
        int pathSum = pref[x]+pref[y]-(2*pref[lca]);
        cout<<pathSum<<"\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0 ;
}