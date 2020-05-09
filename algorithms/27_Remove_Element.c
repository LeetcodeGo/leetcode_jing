/*************************************************************************************** 
Source : https://leetcode.com/problems/remove-element/description/
Author : Jing Kuo

Description:
    Given an array nums and a value val, remove all instances of that value in-place and return the new length.
    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
    The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
    Given nums = [3,2,2,3], val = 3,
    Your function should return length = 2, with the first two elements of nums being 2.
    It doesn't matter what you leave beyond the returned length.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
int removeElement(int* nums, int numsSize, int val) {
    int lIdx=0;
    int rIdx=numsSize-1;
    
    if ((nums==NULL)||(numsSize==0)) return 0;
    
    while(lIdx<=rIdx){
        if(nums[lIdx]==val){
            nums[lIdx]=nums[rIdx];
            rIdx--;
        }else{
            lIdx++;
        }
    }
    return lIdx;
}