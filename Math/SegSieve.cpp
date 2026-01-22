// This is the code for segmented Sieve 
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long 
using namespace std ;
vector<int> Sieve(int n ){
    vector<bool>isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    vector<int>ans;
    for(int i =2;i<=n;i++){
        if(isPrime[i]){
            ans.push_back(i);
            for(int j =1LL*i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return ans;
}
void segSieve(){
    int l,r;
    cin>>l>>r;
    vector<int>basePrimes=Sieve(ceil(sqrt(r)));
    vector<bool>primes(r-l+1,true);
    if(l==1)primes[0]=false;
    for(const auto &pr:basePrimes){
        int curMultiple=(pr+l-1)/pr;
        curMultiple*=pr;
        int sq=pr;
        sq*=pr;
        if(sq>r)break;
        int start = max(curMultiple,sq);
        for(int j =start;j<=r;j+=pr){
            primes[j-l]=false;
        }
    }
    vector<int>ans ;
    for(int i =0; i<r-l+1;i++){
        if(primes[i])ans.push_back(i+l);
    }
    for(const auto it :ans)cout<<it<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cin.tie(0);
    segSieve();
    return 0 ;
}