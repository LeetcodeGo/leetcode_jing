/*************************************************************************************** 
Source : https://leetcode.com/problems/rotate-array/description/
Author : Jing Kuo

Description:
    Given an array, rotate the array to the right by k steps, where k is non-negative.

Example:
    Input: [1,2,3,4,5,6,7] and k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
/*approach 1: 1st:O(n), after:O(1)
  - 1st: create k mapping result (O(n)) 
  - 2nd: find result by map (O(1))

  approach 2: T: O(n), S:O(n)
  - allocation numsSize array
  - write shifted nums to allocated array
  - memcopy allocat array to nums
  - pros:
    a. cache efficeient, 
    b. 2n wirte, 2n addr compute
  - cons:
    cost space
    
  approach 3: T:O(n), S(1)
  - for each idx, compute its final data rather than 
    compute each data->compute its destination -> buffer destination data -> copy this data to destination 
    to save write operations
*/
//approach 3
void rotate(int* nums, int numsSize, int k) {
    int saved_data;
    int shift_cnt=0,base_idx=0;
    int i,pre_idx;
    
    if ((numsSize<=1)||(nums==NULL)) return;
    
    k=k%numsSize;
    if (k==0) return;
    
    while(shift_cnt<numsSize){
        saved_data=nums[base_idx];

        i=base_idx;
        do{
            if(i<k) pre_idx=numsSize-(k-i);
            else    pre_idx=i-k;
            
            if(pre_idx==base_idx) break;
            
            nums[i]=nums[pre_idx];
            shift_cnt++;
            i=pre_idx;
        }while(1);

        nums[i]=saved_data;
        shift_cnt++;
        base_idx++;
    }
    
}