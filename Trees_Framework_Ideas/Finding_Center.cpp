/**
 * Find the Center of the tree .
 * Given that the tree is not rooted at any node .
 * INPUT : no of nodes and Edges 
 * Expected OUTPUT : Node(center) 
 */
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
int n ;
vector<vector<int>>g;
vector<int>dep,par;
void Init(){
    cin>>n;
    g.assign(n+1,{});
    par.assign(n+1,{});
    dep.assign(n+1,{});
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
void DFS(int node,int parent , int depth){
    dep[node]=depth;
    par[node]=parent;
    for(auto &Child:g[node]){
        if(Child!=parent)
            DFS(Child,node,depth+1);
    }

}
vector<int>getCenter(){
    // find any both the nodes between which Diameter lies .
    // Center of the path of Diameter is  the Center node .
    DFS(1,0,0);
    int maxChild= 1;
    for(int j =2;j<=n;j++){
        if(dep[j]>dep[maxChild])
            maxChild=j;
    }
    int nodeFirst = maxChild;
    DFS(maxChild,0,0);
    for(int j =1;j<=n;j++){
        if(dep[j]>dep[maxChild])maxChild=j;    
    }
    int nodeSecond = maxChild ; 
    // Diameter of the Tree connects nodeFirst and nodeSecond 
    vector<int>path;
    int parentNode = nodeSecond;
    while(parentNode!=0){
        /**
         * Loops Works Because parent of our firstNode is 0
         * Initilised during second DFS Call .
         */
        path.push_back(parentNode);
        parentNode=par[parentNode];
    }
    if(path.size()%2==1){
        return vector<int>{path[(path.size())/2]};
    }
    else{
        return vector<int>{path[((path.size())/2) - 1],path[(path.size())/2]};
    }
}
void Solve(){
    Init();
    cout<<"Printing Center Node(s)\n";    
    for(auto &Center:getCenter()){
        cout<<Center<<" ";
    }
    cout<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0 ;
}
