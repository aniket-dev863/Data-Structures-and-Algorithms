/**
 * Given a tree of n nodes, your task is to find a centroid, i.e., 
 * a node such that when it is appointed the root of the tree, each 
 * subtree has at most Floor(n/2) nodes.
 */
#include<iostream>
#include<vector>
#include<utility>
using namespace std ;
int n ;
vector<vector<int>>g;
vector<int>subsz;
vector<int>parent;
void Init(){
    cin>>n;
    g.assign(n+1,{});
    subsz.assign(n+1,{});
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
void DFS(int node ,int parent , int depth){
    subsz[node]=1;
    for(auto &child:g[node]){
        if(child!=parent){
            DFS(child,node,depth+1);
            subsz[node]+=subsz[child];
        }
    }
}
void Solve(){
    Init();
    DFS(1,0,0);
    int par =0 ;
    int cur =1 ;
    while(true){
        int heavy = -1;
        for(auto &child:g[cur]){
            if(child!=par){
                if(subsz[child]>(n/2)){heavy=child;break;}
            }
        }
        if(par!=0 && (n-subsz[cur])>n/2){
            heavy=par;
        }
        if(heavy==-1){
            cout<<cur<<"\n";
            break;
        }
        par=cur;
        cur=heavy;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}