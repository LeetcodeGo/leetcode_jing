/*************************************************************************************** 
Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
Author : Jing Kuo

Description:
    Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:
    Given nums = [0,0,1,1,1,2,2,3,3,4],
    Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
    It doesn't matter what values are set beyond the returned length.

Complexity:
    Time:O()
    Space:O()

Beats: 100% 

Approach: 

***************************************************************************************/
//T:O(n),S:O(1)
int removeDuplicates(int* nums, int numsSize) {
    if((nums==NULL)||(numsSize==0)) return 0;
    
    int idx_write=1;
    int idx_compare=0;
    int idx=0;
    
    while(idx<numsSize){
        if(nums[idx_compare]!=nums[idx]){
            nums[idx_write]=nums[idx];
            idx_write++;
            idx_compare=idx;
        }
        idx++;
    }
    
    return idx_write;
}