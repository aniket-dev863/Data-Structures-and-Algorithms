#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
#define int long long 
int n , k ;
bool Check(vector<int>&Pref,int mid){
    int sz = Pref.size();
    int left = 0;
    int cnt = 0; 
    for(int right = 0; right<sz;right++){
        while(Pref[right]-Pref[left]>mid){
            left++;
        }
        cnt+=(right-left);
    }
    return cnt>=k;
}
void Solve(){
    cin>>n;
    int total = (n*(n+1))/2;
    k=(total+1)/2 ; 
    vector<int>arr(n),Pref(n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        Pref[i+1]=Pref[i]+arr[i];
    }
    int l = 0 ;
    int h = Pref[n]-Pref[0];
    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(Check(Pref,mid)){
            ans = mid ;
            h = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int ts ;
    cin>>ts ;
    while(ts--)Solve();
    return 0 ;
}