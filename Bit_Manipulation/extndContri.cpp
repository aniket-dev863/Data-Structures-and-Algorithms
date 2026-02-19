// Extended Contribution technique based Idea for A problem in Bit Manipulation .
/**
 *  Problem statement
     * Contribution of bits technique 
     *  find : Sum(arr[i]^arr[j])  where i<j ; 
**/
#include<iostream>
#include<bitset>
#include<vector>
using namespace std ;
using ll = long long ;
void solve(){
    ll n ;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll cntOnes[61]={0},cntZeros[61]={0};
    for(int i=0;i<n;i++)
    {    
        for(int j=60;j>=0;j--){
            if((((arr[i])>>(j))&1LL) == 1){
                cntOnes[j]+=1;
            }
            else{
                cntZeros[j]+=1;
            }
        }
    }
    ll ans =0 ;
    for(int i=0;i<=60;i++){
        ll num = cntOnes[i]*cntZeros[i];
        ll toAdd = num * (1LL<<(i));
        ans+=toAdd ;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0; 
}

 /* ***Essence Of this technique is :
 *      Bit Expressions are sum independent on each bit .   
 */