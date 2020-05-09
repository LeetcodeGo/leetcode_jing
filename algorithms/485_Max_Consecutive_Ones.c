/*************************************************************************************** 
Source : https://leetcode.com/problems/max-consecutive-ones/description/
Author : Jing Kuo

Description:
    Given a binary array, find the maximum number of consecutive 1s in this array.
    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000

Example:
    Input: [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s.
        The maximum number of consecutive 1s is 3.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
int findMaxConsecutiveOnes(int* nums, int numsSize) {

    if ((nums==NULL)||(numsSize==0)) return 0;
    
    int ret=0,tmp=0;
    
    for(int idx=0;idx<numsSize;idx++){
        if (nums[idx]==1){
            tmp++;
        }else{ // data  gurentee 1,0 
            if (tmp>ret) ret= tmp; //note:some solution put this outer the if =>waste time
            tmp=0;  
        } 
    }
    if (tmp>ret) return tmp;
    else return ret;
}