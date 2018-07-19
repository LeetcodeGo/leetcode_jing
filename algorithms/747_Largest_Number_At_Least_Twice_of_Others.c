/*************************************************************************************** 
Source : https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
Author : Jing Kuo

Description:
    In a given integer array nums, there is always exactly one largest element.
    Find whether the largest element in the array is at least twice as much as every other number in the array.
    If it is, return the index of the largest element, otherwise return -1.

Example:
    Input: nums = [3, 6, 1, 0]
    Output: 1
    Explanation: 6 is the largest integer, and for every other number in the array x,
    6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.

    Input: nums = [1, 2, 3, 4]
    Output: -1
    Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 
    1. record the 2nd big number, and check 1st big is twice bigger than 2nd big
    2. checking twice rule when finding 1st big (less efficient)

***************************************************************************************/
int dominantIndex(int* nums, int numsSize) {
    if ((numsSize==0)||(nums==NULL)) return -1;
    
    int retIdx=0;
    int big2ndNum=0;
    
    for(int i=1;i<numsSize;i++){
        if (nums[i] > nums[retIdx]){
            big2ndNum=nums[retIdx];
            retIdx=i;
        }else{
            if (nums[i]>big2ndNum) big2ndNum=nums[i];
        }   
    }
    
    if ((big2ndNum<<1)<=nums[retIdx]) return retIdx;
    else return -1;
}


/* approach 2  less efficient
int dominantIndex(int* nums, int numsSize) {
    if (numsSize==0) return -1;
    
    int retIdx=0;
    bool IsTwice=true;
    
    for(int i=1;i<numsSize;i++){
        if (nums[i] > nums[retIdx]){
            if ((nums[retIdx]<<1) <= (nums[i])) IsTwice=true;
            else IsTwice=false;
            
            retIdx=i;
        }else{
            if (IsTwice==true){
                if ((nums[i]<<1) <= (nums[retIdx])) IsTwice=true;
                else IsTwice=false;
            }
        }   
    }
    
    if (IsTwice) return retIdx;
    else return -1;
}
*/