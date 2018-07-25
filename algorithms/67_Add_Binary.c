/*************************************************************************************** 
Source : https://leetcode.com/problems/add-binary/discuss/24783/Simple-C-code-implementing-a-full-adder
Author : Jing Kuo

Description:
    Given two binary strings, return their sum (also a binary string).
    The input strings are both non-empty and contains only characters 1 or 0.

Example:
    Input: a = "1010", b = "1011"
    Output: "10101"

Complexity:
    Time:O(n)
    Space:O(n)

Beats: 100% 

Approach: 

***************************************************************************************/


/* if malloc ret array doesn't want to waste ret[0] if carry ==0
   it may need know final ret size then do malloc in the end
   and set ret[0] = 1 if carry ==1
   Use big array as ret buffer

   By testing the ret cannot allow ret=="0100"

   may be improved by using direct map
   int sum[2][2][2]={
        {{0,1},{1,0}},
        {{1,0},{0,1}}
    };

    int carry[2][2][2]={
        {{0,0},{0,1}},
        {{0,1},{1,1}}
    };
*/

char* addBinary(char* a, char* b) {
    //Q: non-empty definition? null or ""?
    //null check:no need due to precondition
    char carry=0;
    int idxA=strlen(a)-1;
    int idxB=strlen(b)-1;
    char *ret=NULL;
    int retSize;
    int tmp;
    
    //a:the longer string, b:the shorter string
    if(idxA > idxB){
        retSize = idxA;
    }else{
        retSize = idxB;
        
        tmp  = idxA;
        idxA = idxB;
        idxB = tmp;

        tmp=a;
        a=b;
        b=tmp;   
    }

    //add b to a,ends if b is gone through
    for(;idxB>=0;idxB--,idxA--){
        a[idxA]=a[idxA]-'0';
        b[idxB]=b[idxB]-'0';
        
        tmp=b[idxB]^a[idxA]^carry;
        carry=(carry&b[idxB])|(carry&a[idxA])|(b[idxB]&a[idxA]);
        a[idxA]=tmp+'0';
    }
    
    //if has carry, add to a
    for(;idxA>=0;idxA--){
        if (carry==0) break;

        a[idxA]=a[idxA]-'0';
        tmp=carry^a[idxA];
        carry = carry&a[idxA];
        a[idxA]=tmp+'0';
    }
    
    if(carry==1){
        ret=malloc(sizeof(char)*(retSize+3));
        ret[0]='1';
        memcpy(&ret[1],a,retSize+2);
    }else{
        ret=malloc(sizeof(char)*(retSize+2));
        memcpy(&ret[0],a,retSize+2);
    }
    
    return ret;
}