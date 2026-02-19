#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std ;
#define int long long 
int n;
/**
 * Returns the total number of 1 's in the binary representation 
 * of the of all numbers from [1......n] inclusive of n 
 */
void numberOfOnes(){
    cin>>n;
    int ans =0;
    for(int i=60;i>=0;i--){
        int blockContri = ((n+1)/(1LL<<(i+1)))*(1LL<<i);
        int leftContri = max( 1LL*(((n+1)%(1LL<<(i+1)))-(1LL<<(i))) , 1LL*0 );
        ans+=blockContri+leftContri;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    numberOfOnes();
    return 0;
}

/***
 * Note Important :
 * If we are going beyond 30 bits we need 1LL always .
 * 1<<(i+1) --> Wrong here (correct only if i<=30 ) 
 * 1LL<<(i+1) --> Corect 
 */