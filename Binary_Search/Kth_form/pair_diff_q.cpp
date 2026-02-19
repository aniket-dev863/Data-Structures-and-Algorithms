/**
 * You are given an integer array nums of length N.
 *  We want to find the k th
 * smallest absolute difference between any two elements (nums[i], nums[j]) where i<j.
 */
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std ;
vector<int>arr ;
int n,k ;
bool check(int mid) {
    int count = 0;
    int left = 0;
    
    // We iterate 'right' from 0 to n-1.
    // For every 'right', we find how many valid 'left's exist.
    for (int right = 0; right < n; right++) {
        
        // While the distance is too big, shrink the window from the left
        while (arr[right] - arr[left] > mid) {
            left++;
        }
        
        // All indices from 'left' to 'right-1' are valid partners for 'right'.
        // The count of such indices is: right - left
        count += (right - left);
    }
    
    return count >= k;
}
void solve(){
    cin>>n;
    arr.clear();
    for(int i=0;i<n;i++){
        int num ;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    cin>>k;
    int l = 0; 
    int h = arr[n-1]-arr[0];
    int ans = -1;
    while(l<=h){
        long long mid = (l+h)/2;
        cout<<mid<<"\n";
        if(check(mid)){
            ans=mid ;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    solve();
    return 0 ;
}