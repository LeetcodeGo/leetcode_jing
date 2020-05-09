/*************************************************************************************** 
Source : https://leetcode.com/problems/move-zeroes/description/
Author : Jing Kuo

Description:
    Given an array nums, write a function to move all 0's to the end of it 
    while maintaining the relative order of the non-zero elements.

Example:
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: Very interesting question. Note this is no need to do swap operation

***************************************************************************************/
void moveZeroes(int* nums, int numsSize) {
    int wirteIdx=0;

    if (numsSize < 2) return;
    
    for (int i=0;i<numsSize;i++){
        if (nums[i]!=0){
            nums[wirteIdx] = nums[i]; 
            wirteIdx++;
        }
    }
    
    for(;wirteIdx<numsSize;wirteIdx++){
        nums[wirteIdx]=0;
    }
}