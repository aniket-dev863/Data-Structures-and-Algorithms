// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;
// #define int int64_t 
// #define ll int64_t
// int n,q;
// ll maxXOR(vector<vector<ll>> & Pre,ll l,ll r){
//     int n=Pre.size();
//     ll ans = 0;
//     for(int i=0;i<n;i++){
//         int numCnt = r-l+1;
//         int numOnes=Pre[i][r+1]-Pre[i][l];
//         int numZeros= numCnt-numOnes;
//         if((numOnes>numZeros)||(numOnes==numZeros)){
//             ans+=0*(1LL<<(n-i));
//         }
//         else if((numOnes<numZeros )&& (numOnes!=0)){
//             ans+=1*(1LL<<(n-i));
//         }
//     }
//     return ans ; 
// }

// ll maxAND(vector<vector<ll>> & Pre,ll l,ll r){
//     int n = Pre.size();
//     ll ans = 0; 
//     for(int i= 0;i<n;i++){
//         int numCnt = r-l+1;
//         if((Pre[i][r+1] - Pre[i][l])>0){
//             ans+=1*(1LL<<(n-i));
//         }
//     }
//     return ans ;
// }
// ll maxOR(vector<vector<ll>> & Pre,ll l,ll r){
//     int n = Pre.size();
//     ll ans = 0; 
//     int numCnt=r-l+1;
//     for(int i=0;i<n;i++){
//         int numOnes=Pre[i][r+1]-Pre[i][l];
//         //cout<<numOnes<<"\n";
//         if(((numOnes)<numCnt)){
//             ans+=1*(1LL<<(n-i));
//         }
//         //cout<<ans<<"\n";    
//     }
//     return ans ;
// } 
// void Solve(){
//     cin>>n;
//     ll arr[n];
//     ll numBits = 0;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         numBits=max(numBits,(ll)floor(log2(arr[i])));
//     }
//     cin>>q;
//     numBits=31;
//     //cout<<numBits<<"\n";
//     vector<vector<ll>>pOnes;
//     for(int i=numBits;i>=0;i--){
//         vector<ll>pre(n+1,0);
//         ll cntOnes=0;
//         for(int j=0;j<n;j++){
//             pre[j]=cntOnes;
//             if((arr[j]>>i)&1){
//                 cntOnes++;
//             }
//         }
//         if(cntOnes!=0){
//             pre[n]=cntOnes;
//         }
//         pOnes.push_back(pre);
//     }
//     /**
//     for(auto it :pOnes){
//         for(auto el:it){
//             cout<<el<<" ";
//         }
//         cout<<"\n";
//     }
//     /**
//      * Tested : Works Fine 
//      */
//     for(int i=0;i<q;i++){
//         ll l ,r;
//         cin>>l>>r;
//         l--;r--;
//         ll x1 = maxXOR(pOnes,l,r);
//         ll x2= maxAND(pOnes,l,r);
//         ll x3 =maxOR(pOnes,l,r);

//         ll ans=x1+x2+x3;
//         cout<<ans<<"\n";        
//     }
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     ll ts;cin>>ts;
//     while(ts--)Solve();
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std ;
const int BITS = 32 ;
#define ll int64_t 
ll maxXOR(vector<vector<ll>>&Pre , ll l , ll r ){
    int numCount = r-l+1;
    ll ans=0 ;
    for(int i=0;i<BITS;i++){
        int numONES = Pre[i][r+1]-Pre[i][l];
        int numZEROS = numCount-numONES;
        if(numONES<numZEROS){
            ans+=1*(1LL<<i);
        }
    }
    return ans;
}
ll maxAND(vector<vector<ll>>&Pre,ll l, ll r){
    int numCount=r-l+1;
    ll ans=0 ;
    for(int i=0;i<BITS;i++){
        int numONES=Pre[i][r+1]-Pre[i][l];
        if(numONES>0){
            ans+=(1LL<<i);
        }
    }
    return ans;
}

ll maxOR(vector<vector<ll>>&Pre,ll l ,ll r){
    int numCount =r-l+1;
    ll ans=0;
    for(int i=0;i<BITS;i++){
        int numONES=Pre[i][r+1]-Pre[i][l];
        if(numONES<numCount){
            ans|=(1LL<<i);
        }
    }
    return ans;
}
int n,q;
void Solve(){
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<ll>>Pre(BITS,vector<ll>(n+1,0));
    for(int i=0;i<BITS;i++){
        for(int j=0;j<n;j++){
            Pre[i][j+1]+=Pre[i][j];
            Pre[i][j+1]+=((arr[j]>>i)&1);
        }
    }
    // Processing Queries 
    cin>>q;
    for(int i=0;i<q;i++){
        ll l ,r;
        cin>>l>>r;
        l--;r--;
        ll x1 =maxXOR(Pre,l,r) ;
        ll x2 =maxOR(Pre,l,r) ;
        ll x3 =maxAND(Pre,l,r);
        ll ans=x1+x2+x3;
        cout<<ans<<"\n"; 
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0;
}