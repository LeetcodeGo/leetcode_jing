/*************************************************************************************** 
Source : https://leetcode.com/problems/plus-one/description/
Author : Jing Kuo

Description:
    Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
    The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
    You may assume the integer does not contain any leading zero, except the number 0 itself.

Example:
    Input: [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.

Complexity:
    Time:O(n)
    Space:O(n)

Beats: 100% 

Approach: 

***************************************************************************************/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *retArray;       
    int i=digitsSize-1;
                        
    for(;i>=0;i--){  
        if (digits[i]==9){
            digits[i]=0;
        }else{
            digits[i]+=1;
            break;
        } 
    }
    
    if (i==-1){
        *returnSize=digitsSize+1;
        retArray=malloc(sizeof(int)*(*returnSize));
        memcpy(&retArray[1],digits,sizeof(int)*digitsSize);
        retArray[0]=1;
    }else{
        *returnSize=digitsSize;
        retArray=malloc(sizeof(int)*(*returnSize));
        memcpy(retArray,digits,sizeof(int)*digitsSize);
    }

    return retArray;
}

/* digits[i]+=carry;  can be replaced
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *retArray;
    int carry=1;                                   
                        
    for(int i=digitsSize-1;i>=0;i--){
        digits[i]+=carry;   
        if (digits[i]>9){
            carry=1;
            digits[i]=0;
        }else{
            carry=0;
            break;
        } 
    }
    
    if (carry==1){
        *returnSize=digitsSize+1;
        retArray=malloc(sizeof(int)*(*returnSize));
        memcpy(&retArray[1],digits,sizeof(int)*digitsSize);
        retArray[0]=carry;
    }else{
        *returnSize=digitsSize;
        retArray=malloc(sizeof(int)*(*returnSize));
        memcpy(retArray,digits,sizeof(int)*digitsSize);
    }

    return retArray;
}/*

/* bad solution, waste retArray[0] if carry==1
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *retArray=malloc(sizeof(int)*(digitsSize+1));
    int carry=1;                                   
                        
    for(int i=digitsSize;i>=1;i--){
        retArray[i] = digits[i-1]+carry;
        if (retArray[i]>9){
            carry=1;
            retArray[i]=0;
        }else{
            carry=0;
        }   
    }
                         
    if (carry == 1){
        *returnSize=digitsSize+1;
        retArray[0]=1;
        return retArray;
    }else{
        *returnSize=digitsSize;
        retArray[0]=0;
        return &retArray[1];
    }     
}
*/