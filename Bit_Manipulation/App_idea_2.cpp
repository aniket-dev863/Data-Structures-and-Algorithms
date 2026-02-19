/**
 * Problems Statemet:
 * Problem Statement: Given an array of N positive integers. You can perform this operation any
 * number of times, choose two indices x and y. If array[x] = a and array[y] = b, then after the
 * operation
 *           array[x] = a OR b, array[y] = a AND b.
 * Perform the operations optimally such that ∑array[i]*array[i] for all 1<=i<=n is maximum. 
 * Print the largest sum of squares you can get after performing the operations greater 
 * than equal to zero times.
 */
#include<iostream>
#include<vector>
using namespace std;
#define int long long 
void Solve(){
    // find the number of ones in the bit position 
    // if the number of ones in the 
    int n ;cin>>n;
    int arr[n];int noOfBits = 0 ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        noOfBits=max(noOfBits,(int)floor(log2(arr[i])));
    }
    noOfBits++;
    //cout<<noOfBits<<"\n";
    vector<int>countOnes(noOfBits,0);
    for(int i=noOfBits ;i>=0;i--){
        for(int j=0;j<n;j++){
            if(((arr[j]>>i)&1) == 1)countOnes[i]++;
        }
    }
    // for(const auto it :countOnes){
    //     cout<<it<<"\n";
    // }
    int mi = 1e9 ;
    for(int i=0;i<noOfBits;i++){
        cout<<i<<"th Bit has "<<":"<<countOnes[i]<<" Ones"<<"\n";
        mi = min(countOnes[i],mi);
    }
    
    int ans = 0 ;
    for(int i =0 ; i<n;i++){
        int maxNumPossible = 0 ;
        for(int j =0 ;j<noOfBits;j++){
            if(countOnes[j]){
                maxNumPossible|=(1<<j);
                countOnes[j]--;
            }
        }
        ans+=(maxNumPossible*maxNumPossible);
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0 ; 
}
