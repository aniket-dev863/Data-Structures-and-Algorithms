/**
 * Main idea to find the diameter of any tree , not only a binary tree but any tree .
 * Steps
 *  1) Choose any node (x) 
 *  2) Find the farthest node from (x) lets say (y).   --> USE BFS 
 *  3) Find the farthest node from (y) .               --> USE BFS
 *  4) Distance between y and the farthest node is diameter . 
 *  EASY 2 DFS Trick .
 */
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std ;

/**
 *  Convert int to long long to avoid signed integer overflow.
 *  long long main(){} --> Incorrect 
 *  signed main(){} --> Correct 
 */
#define int long long 

int n ;
vector<vector<int>>g ;
vector<int>depth,parent;
/**
 * Initialisation Module
 */
void Init(){
    cin>>n;
    g.assign(n+1,{});
    depth.assign(n+1,{});
    parent.assign(n+1,{});
    for(int i=0 ;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
}
/**
 * Depth First Search Module 
 */
void DFS(int node ,int par,int dep){
    depth[node]=dep  ;
    parent[node]=par ;
    for(auto &child:g[node]){
        if(child!=par){
            DFS(child,node,dep+1);
        }
    }
}
void solve(){
    Init();
    // Finding the Diameter of the tree
    DFS(1,0,0);
    int maxch=1;
    for(int j =2;j<=n;j++){
        if(depth[j]>depth[maxch])
            maxch=j;
    }
    DFS(maxch,0,0);
    cout<<maxch<<"\n"; // for purpose of checking 
    for(int j =1;j<=n;j++){
        if(depth[j]>depth[maxch])
            maxch=j;
    }
    cout<<maxch<<"\n"; // for purpose of checking 
    //Diameter
    cout<<depth[maxch]<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int ts ; cin>>ts;
    while(ts--)
        solve();
    return 0 ;
}