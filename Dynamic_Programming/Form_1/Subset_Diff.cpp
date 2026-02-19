/**
 *  Given a array divide ,Alice and Bob decide to create 2 subsets out of this array with different elements , Alice is genuis of Abstract algebra so he helps bob to pick up elements for his subset in such a way that difference between the Sum of subsets is as minimum as Possible .
 * 
 * Your Task is to find what is the minimum Differce Between both of their subsets .
 * 
 * Input : Arr[ 1 , 3 ,2 ] Output = 0 ; 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int n ; 
int arr[250],totalSum;
int dp[250][25000];
vector<int>s1,s2;
int rec(int level,int currentSum){
    // Prunning 
    /**
     * No need to prun at the level case where currentSum >= totalSum/2 ;
     */
    // base Case
    if(level==n){
        return abs((2*currentSum)-totalSum);
    } 
    // Cache Check 
    if(dp[level][currentSum]!=-1){
        return dp[level][currentSum];
    }
    // Transition
    int ans = min(rec(level+1,arr[level]+currentSum),rec(level+1,currentSum));
    // Save and return 
    return dp[level][currentSum]=ans ; 
}

void generate(int level , int currentSum){
    if(level==n){
        return ;
    }
    int a = rec(level+1,arr[level]+currentSum);
    int b = rec(level+1,currentSum) ;
    if(min(a,b)==a){
        s1.push_back(arr[level]);
        generate(level+1,arr[level]+currentSum);
        return ;
    }
    else{
        s2.push_back(arr[level]);
        generate(level+1,currentSum);
        return ;
    }
}
void Solve(){
    cin>>n;
    s1.clear();s2.clear();
    totalSum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        totalSum+=arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<"Minimum Difference between 2 sets is :"<<rec(0,0)<<"\n";
    generate(0,0);
    cout<<"Elements in S1 Are:\n";
    for(const auto e:s1){
        cout<<e<<" ";
    }
    cout<<"\nElements in S2 Are:\n";
    for(const auto e:s2){
        cout<<e<<" ";
    }
    cout<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solve();
    return 0;
}
// Level up print both s1 and s2 . 
/**
 * To print S1 and S2 we have go in that direction where we get minimum ,
 * to generate the both subsets s1 and s2  
 */