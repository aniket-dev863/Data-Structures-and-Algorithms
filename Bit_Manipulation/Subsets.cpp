#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
int main(){
    int arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(int);
    for(int mask =0;mask<(1<<n);mask++){
        for(int i= 0;i<n;i++){
            if((mask>>i)&1){
                cout<<arr[i]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}