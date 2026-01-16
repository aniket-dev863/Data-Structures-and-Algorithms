/**
 * 🧠 Guiding thought :
 * Edge-contribution only works when counting the child side of each edge.\
 * Always compute contributions inside DFS when returning from a child.
 */
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
int n ;
vector<vector<int>>g;
vector<int>subsz;
int ans =0 ;
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
void DFS(int node ,int parent){
    subsz[node]=1;
    for(auto &child:g[node]){
        if(child!=parent)
        {
            DFS(child,node);
            subsz[node]+=subsz[child];
            ans+=subsz[child]*(n-subsz[child]);
        }
    }
}
void Solve(){
    Init();
    DFS(1,0);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0;
}