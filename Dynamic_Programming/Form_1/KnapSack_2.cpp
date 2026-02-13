// Atcoder question knapsack -2 
// where contraints of weight are upto 1e9 ;
// so we cannot use weight to cache our maxvalue atainable at a particualar .

/**
 * Final Solution Approach is :
 *    1<=val[i]<=1e3;
 *    So Maximum value that are possible to get  is 1e5 ; Minimum is 1 ;
 *    So our Answer Will lie Between 1 to 1e5 ; 
 */
#include<iostream>
#include<algorithm>
using namespace std ;
using ll = long long ;
ll n,targetValue,maxWeight ;
ll weight[105];
ll val[105];
ll dp[105][100100];
/**
 * Return minimum weight required to get the Value .
 */
ll rec(ll level , ll remValue){
    //Prunning
    //BaseCase
    if(level==n){
        return (remValue==0)?0:1e15;
    }
    //CacheCheck
    if(dp[level][remValue]!=-1){
        return dp[level][remValue] ;
    }
    //Recursion 
    ll ans = rec(level+1,remValue);
    if(remValue>=val[level]){
        ans=min(ans,weight[level]+rec(level+1,remValue-val[level]));
    }
    
    //save and Return
    return dp[level][remValue]=ans;
}
void solve(){
    cin>>n>>maxWeight;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>val[i];
    }
    targetValue=1e5;
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(ll i=1e5;i>=1;i--){
        if(rec(0,i)<=maxWeight){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0; 
}

/**
 * Testing the recurrance relation . 
 * weight : 2 5 7 10
 * value  : 6 6 1 3
 *  
 * Tested Works : Fine ;
 * 
 * Safe for Caching .
 */

 /**
  * Important point to be noted here is Resability of the states .
  * 
  *    REUSABILITY OF STATES IN  DYNAMIC PROGRAMMING \
  *         
  *     1)  value of our  sates does't depend on the chainging goal value .
  *     2)  value of our inermediate also does'nt depend on how we reached this state .
  */