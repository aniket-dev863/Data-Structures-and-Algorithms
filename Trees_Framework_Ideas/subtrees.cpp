/**
 * This is the code for the number of 
 * nodes children in a Subtree of a Particualar Node .
 * 
 * It is Defined that the tree is rooted at the a Particular node .
 */
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std ;
// Global DS used in multiple Functions.
int n ;                         // number of node 
vector<vector<int>> g ;         // Adjacency List to store the Tree Neighbours  
vector<int>subtreeSize ;        // Subtree Sizes of different nodes 
vector<int>par ;                // Maintaing the parent of each node  
vector<int>subFar ;             // Vector Storing Farthest dept of the farthest node in that Subtree .  

/**
 * 
 */
void dfs(int node , int parent ){
    subtreeSize[node]=1;
    par[node]=parent ;
    for(auto child : g[node]){
        // esuring the parent is not traversed back .
        if(child != parent){
            dfs(child,node);
            subtreeSize[node]+=subtreeSize[child] ;
            subFar[node]=max(subFar[node],1+subFar[child]);
        }
    }
}
void solve(){
    cin>>n;      // number of nodes
    g.assign(n+1,{}); // Building Empty List 
    subtreeSize.assign(n+1,0); // Initailising subtree Sizes to 0 ; 
    par.assign(n+1,{}); // Empty Parent List 
    subFar.assign(n+1,0);
    // building a adjacency list of a tree 
    for(int i =0;i<n-1;i++){
        int a ,b ;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}