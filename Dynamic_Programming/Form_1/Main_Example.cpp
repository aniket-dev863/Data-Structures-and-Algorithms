/**
 * Question : 
 *  Given a String with blanks retun number of ways to fill the 
 *  blank spaces in the string using some fixed given letters 
 *  such that the following conditions are met .
 *  Conditions:
 *      1.No two neighbours are same.
 *      2.Also add a follow-up what if the string is circular.
 *      3.Number of A's Need to be odd in the final answer .    
 *      4.Print the LexicoGraphically Smallest solution .
 * 
 * 
 *  Input:
 *      S = ??A?B?D? , N = s.size() .
 *  
 *  Output:
 *    For Every Condition output the optimum answer available.  
 */

// <------------------ANSWER----------------------------------------------------------->

    /**
     * Steps to Solve any Dynamic Programming Question .
     * 
     *  Step 1 Analyse the DP Form . ( Read the Questions carefully ) . 
     *  Step 2 State Formulation . 
     *          a. What goes in as a parameter to the function 
     *          b. What comes out as a return value 
     *  Step 3 Transition between Initial input to return value.
     *  Step 4 Time Complexity Check 
     *  Step 5 Write Code (Always Remember writing code comes at the last 🤣)
     */

// <----- BUILDING_SOLUTION------------------------------------------------------------->
    /**
     * Obseravtions :
     *      1. There are 4 options at every blank space available .
     *      2. only one option where the blank space is not there .
     */

// <-------------------CODE------------------------------------------------------------->
     
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std ;
#define int long long
int getChar(char c){
    if(c=='A')return 1;
    if(c=='B')return 2;
    if(c=='C')return 3;
    if(c=='D')return 4;

    return 0;
}
int n ;string s;

    /***
     * DP Memo : memo[current Level][start State][Prev State][Party]
     * State can be from 0 to 4 ;
     * 0 for the innitial caller ;
     * Parity either 0 /1 ;
     */

int memo[1001][5][5][2];
int rec(int i , int start,int prev , int cnta){
    //PRUNNING 
    //BASE CASE 
   if(i==n){
    return (cnta==1)?1:0;
   }
   // CACHE CHECK
   if(memo[i][start][prev][cnta]!=-1){
    return memo[i][start][prev][cnta];
   }
   // TRANSITION 
   int ans =0;
   int currentCharIndex = getChar(s[i]);
   vector<int>candidates;
   if(currentCharIndex==0)candidates={1,2,3,4};
   else candidates={currentCharIndex};
   for(auto charCode:candidates){
        if(charCode==prev)continue;
        
        int nextParity=cnta;
        if(charCode==1)nextParity^=1;
        
        int nextStart = (i==0)?charCode : start ;
        
        ans = (ans+rec(i+1,nextStart,charCode,nextParity));
    }
    // SAVE AND RETURN
    return memo[i][start][prev][cnta]=ans; 
}
void Solve(){
    cin>>n>>s;
    memset(memo,-1,sizeof(memo));
    cout<<rec(0,0,0,0)<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0 ;
}

// <----- IMPLEMENTATION SOLUTION------------------------------------------------------------->
/**
 *              Clean coding & competitive programming style tips (bite-sized)
 * 
 * Never mutate state parameters that are logically inputs. Always compute nextX.
 * Prefer small integer indices for DP dimensions (0..4) rather than -1.
 * Memoize early: add if(res != -1) return res; before heavy computation.
 * Avoid heavy allocations inside recursion. No set/vector creation per call.
 * Use iterative loops for (int c=1;c<=4;c++) — fast and clear.
 * When adding circular constraints, prefer outer loop over first char — easier than enlarging state.
 * If final counts can be large, decide modulo early to avoid overflow.
 * Write base cases clearly: they are the contract of your recursion.
 */