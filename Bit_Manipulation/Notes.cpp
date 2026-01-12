/**
 * This are the must know tricks .
 */

#include<iostream>
#include<vector>
using namespace std ;
int main(){
    // int i ; 
    // int n ;
    // /**
    //  * Check if ith bit is set .
    //  * using AND and right shift.
    //  */
    // bool set = (n&(1<<i)==1)?1:0;
    // /**
    //  * Set the ith bit using a OR operator
    //  * 1 | 1 -> 1
    //  * 0 | 1 -> 1
    //  */
    // n=n|(1<<i);
    // /**
    //  * Unset the current bit ;
    //  * using AND 111001 & 101111 --> 101001
    //  * here we have unset the 1  0  1  0  0  1
    //  *                        5  4  3  2  1  0
    //  * 4 th bit .
    //  */
    // n=n&(~(1<<i));

    // /**
    //  * Toggle the ith bit 
    //  * we will use the xor operator to toggle.
    //  * 1 ^ 1 --> 0 ;
    //  * 0 ^ 1 --> 1 ;
    //  * Any bit Xor with 1 will toggle 
    //  *  0->1 
    //  *  1->0 
    //  */
    // n=n^(1<<i) ;
    // /**
    //  * Check if the number is odd or even
    //  *      1 0 0 0 1
    //  *      4 3 2 1 0 
    //  * if the 0 th bit is set ie 1 then the number is odd.
    //  * else even 
    //  */ 
    // if(n&1)cout<<"it a ODD number ";
    // else cout<<"its a even number ";

    // /**
    //  * Mutiplying any number by 2^n 
    //  * the left Shift operation 
    //  * like (1<<n);
    //  * Detail Walkthrough 
    //  *      Initial : 1  --> Base 10 :1 
    //  *      n=2 ;   
    //  *      operation : (1<<n) ;
    //  *      Result :  1 0 0   ---> Base 10 : 4 
    //  *      BitPosn:  2 1 0
    //  *      Conclusion: Multiplied Number by 2^n ;
    //  */
    // n=(n<<10);
    // /**
    //  * Divide any number by 2^n ; 
    //  * the right shift operation 
    //  * like (4>>n);
    //  * Detail Walththrough :
    //  *      Initial: 100  --> 4 
    //  *      n=2;
    //  *      operation (4>>2);
    //  *      Result: 1  --> 1 
    //  *      Conclusion : n bit shift divide by 2^n
    //  */

    int  a = INT_MAX;
    cout<<a+1<<"\n";
    return 0;
}