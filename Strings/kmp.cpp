// String matching algorithm 
// Rabin Karp algorithm 
#include<iostream>
#include<vector>
#include<string>
using namespace std ;
/**
 * KMP : String matching algorithm
 */
vector<int> kmp(string s){
    vector<int>lps(s.size(),0);
    for(int i=1;i<(int)lps.size();i++){
        int prev_idx = lps[i-1];
        while(prev_idx>0 && s[i]!=s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }
        lps[i]=prev_idx+(s[i]==s[prev_idx]?1:0);
    }
    return lps;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s ;
    cin>>s;
    string toMatch ;
    cin>>toMatch;
    string sNew = toMatch+'#'+s;
    vector<int>v=kmp(sNew);
    int cnt= 0;
    for(int i=(int)toMatch.size();i<(int)v.size();i++){
        if(v[i]==(int)toMatch.size()){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}