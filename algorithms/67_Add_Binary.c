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
*/
char* addBinary(char* a, char* b) {
    //Q: non-empty definition? null or ""?
    //null check:no need due to precondition
    
    char carry=0;
    int idxA=strlen(a)-1;
    int idxB=strlen(b)-1;
    int longArrayIdx,smallArrayIdx;
    char *longArray, *smallArray;
    char *ret=NULL;
    int retSize;
    char tmp;
    
    if(idxA > idxB){
        longArrayIdx = idxA;
        smallArrayIdx = idxB;
        longArray  = a;
        smallArray = b;
        retSize = idxA;
    }else{
        longArrayIdx  = idxB;
        smallArrayIdx = idxA;
        longArray  = b;
        smallArray = a;    
        retSize = idxB;
    }

    for(;smallArrayIdx>=0;smallArrayIdx--,longArrayIdx--){
        longArray[longArrayIdx]=longArray[longArrayIdx]-'0';
        smallArray[smallArrayIdx] = smallArray[smallArrayIdx]-'0';
        
        tmp=smallArray[smallArrayIdx]^longArray[longArrayIdx]^carry;
        carry=(carry&smallArray[smallArrayIdx])|
              (carry&longArray[longArrayIdx])|
              (smallArray[smallArrayIdx]&longArray[longArrayIdx]);
        longArray[longArrayIdx]=tmp+'0';
    }
    
    for(;longArrayIdx>=0;longArrayIdx--){
        if (carry==0) break;

        longArray[longArrayIdx]=longArray[longArrayIdx]-'0';
        tmp=carry^longArray[longArrayIdx];
        carry = carry&longArray[longArrayIdx];
        longArray[longArrayIdx]=tmp+'0';
    }
    
    if(carry==1){
        ret=malloc(sizeof(char)*(retSize+3));
        ret[0]='1';
        memcpy(&ret[1],longArray,retSize+2);
    }else{
        ret=malloc(sizeof(char)*(retSize+2));
        memcpy(&ret[0],longArray,retSize+2);
    }
    
    return ret;
}