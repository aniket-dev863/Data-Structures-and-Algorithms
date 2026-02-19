#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <climits>

using namespace std;

// Typedefs for convenience
typedef   int ll ; 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;


// Fast IO
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll n ,arr[210];
ll dp[210][21000][21000] ;
  
ll rec(ll level ,ll bucketA,ll bucketB){
    // prunning
    // base Case
    if(level==n){
        return (bucketA==bucketB)?1:0;
    }
    // cache check
    // if(dp[level][bucketA][bucketB]!=-1){
    //    return dp[level][bucketA][bucketB] ;
    // }
    // transition
    ll ans = (
        rec(level+1,bucketA+arr[level],bucketB) |
        rec(level+1,bucketA,arr[level]+bucketB) 
            
    );
    // save and return
    return ans ; 
}
void Solve(){
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    // memset(dp,-1,sizeof(dp));
    if(rec(0,0,0))cout<<"Possible\n";
    else cout<<"Not Possible\n";
}
int main() {
    fastIO();
    Solve();
    return 0;
}
