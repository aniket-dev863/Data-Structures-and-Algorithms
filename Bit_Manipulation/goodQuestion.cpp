/**
 * Find the position of the k th set bit in a string made up of concatenation the 
 * binary representation of all the numbers from [1 <= x <= 1e9 ] . 
 * 
 * Function :numberOfOnes(int x) returns number of 1 's in binary rep of all numbers from [1--x] ; 
 * 
 * Using binary Search on our defined search space is the key here . 
 * 
 */

 /**
  * Binary Search Idea Building 
  * 
  *  1  2   3   4   5   6   7   8
  *  
  */
 #include<iostream>
 #include<vector>
 #include<bitset>
 using namespace std;
 using ll = long long ;
 ll k ;
/**
 * This function returns the position of k th set bit in the String . 
 */
ll totalBits(ll x)
{    
    ll ans =0;
    ll len =1;
    ll num=1;
    while (num<=x)
    {
        ll sameTill=(num*2)-1;
        if(sameTill<=x){
            ans+=len*(sameTill-num+1);
            num=sameTill+1;
            len++;
        }
        else{
            ans+=len*(x-num+1);
            break;
        }
    }
    ans++;
    return ans ;
}
ll totalOnes(ll x ){
    ll ans = 0; 
    for(int i=60;i>=0;i--){
        ll blockContri=((x+1)/(1LL<<(i+1)))*(1LL<<i) ;
        ll leftContri= max(1LL*((x+1)%(1LL<<(i+1)) - (1LL<<i)),1LL*0);
        ans+=blockContri+leftContri;
    }
    return ans ;
}
ll findKthOne(ll k){
    ll low = 0;
    ll high = k ;
    ll ans = -1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(totalOnes(mid)>=k){
            ans=mid;
            high =mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans ; 
}
string toBinary(ll x ){
    unsigned long long u = (unsigned long long )x ;
    string ans="";
    while(u>0){
        if(u%2==1)ans+='1';
        else ans+='0';
        u/=2;
    }
    if(ans=="")ans="0";
    reverse(ans.begin(),ans.end());
    return ans ;  
}
void solve(){
     cin>>k;
    // cout<<totalOnes((ll)4)<<"\n";
    ll num = findKthOne((ll)k);
    //cout<<num<<"\n";
    ll pos_in_num = k -totalOnes(num-1);
    //cout<<pos_in_num<<"\n";
    //ll final_pos_ans = (floor(log2(num))+1)*(num-1);
    //cout<<final_pos_ans<<"\n";
    ll final_pos_ans = totalBits(num-1); 
    string binNum = toBinary(num);
    //cout<<binNum<<"\n";
    int cnt=0;
    int sz =binNum.size() ; 
    for(int i=0;i<sz;i++){
        cnt++;
        //cout<<binNum[i]<<"\n";
        if(binNum[i]=='1'){
            pos_in_num--;
            if(pos_in_num==0)break;
        }
    }
    final_pos_ans+=cnt;

    cout<<final_pos_ans<<"\n";
 }
 int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
 }