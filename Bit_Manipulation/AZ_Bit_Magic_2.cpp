// Bit Magic 2
#include<iostream>
using namespace std;
using ull = unsigned long long ;
using ll = long long;
void binary(ll x){
    ull u = (ull)x;
    for(int i=63;i>=0;i--){
        if((u>>i)&1){
            cout<<"1";
        }
        else
            cout<<"0";
    }
    cout<<"\n";
}
int msb(ll x){
    ull u =(ull)x;
    if(x==0)return -1;
    return 63-(__builtin_clzll(u));
}
int rsb(ll x){
    ull u = (ull)x;
    if(x==0)return -1;
    else return (__builtin_ctzll(u));
}

int isPow2(ll x){
    if(x<=1)return 0;
    else return ((x&(x-1))==0);
}
ll bigPowTwo(ll x){
    if(x==0)return -1;
    ull u = (ull)x;
    return 1LL<<(__builtin_ctzll(u));
}

ll smalestPowTwo(ll x){
    if(x<=1)return 2;
    if(x<0)return 2;

    ull u = (ull)x;
    if((u&(u-1))==0)return (ll)u;
    int msb = 63-(__builtin_clzll(u));
    return 1LL<<(msb+1);
}
void Solve(){
    ll n ;
    cin>>n;
    binary(n);
    cout<<msb(n)<<"\n";
    cout<<rsb(n)<<"\n";
    cout<<isPow2(n)<<"\n";
    cout<<bigPowTwo(n)<<"\n";
    cout<<smalestPowTwo(n)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;cin>>t;
    while(t--){
        Solve();
    }
}

// __built_popcount(x) --> number of 1 s in the binary rep

/**
 * __buitin_clz(x) -> returns the number of leading zeros
 * __builtin_ctz(x) --> returns the number of trailing zero's
 * check if its a power of 2 : (x &(x-1))
 *      1111111111111111111111111111111111111111111111111111111111111101
 *      1111111111111111111111111111111111111111111111111111111111111101
 * 
 */