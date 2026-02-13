// return the  the index of all the elements used to generate the 
// particular subset sum in from the given array . 
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std ;
int n,targetSum;
int arr[100100];
int dp[105][100100];
int rec(int level,int currentSum){
    //Prunning 
    //base case
    if(level==n){
        return (targetSum==currentSum)?1:0;
    }
    // cacheCheck
    if(dp[level][currentSum]!=-1){
        return dp[level][currentSum];
    }
    //transition
    int ans=0;
    ans+=rec(level+1,currentSum);
    if(currentSum+arr[level]<=targetSum){
        ans+=rec(level+1,arr[level]+currentSum);
    }
    //save and return 
    return dp[level][currentSum]=ans ;
}
set<int>s;
void generate(int level,int currentSum){
    if(level==n){
        return ;
    }
    //transition
    if(rec(level+1,currentSum)>0){
        generate(level+1,currentSum);
        return ;
    };
    if(rec(level+1,arr[level]+currentSum)>0){
        s.insert(level);
        generate(level+1,arr[level]+currentSum);
        return ;
    };

}
void Solve(){
    cin>>n>>targetSum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    generate(0,0);
    for(const auto it :s)cout<<it<<" ";
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0 ;
}