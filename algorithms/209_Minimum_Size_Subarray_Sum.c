/*************************************************************************************** 
Source : 
Author : Jing Kuo

Description:
    Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:
    Input: s = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
/*
- BF approach 1: S:O(n^2), T:O(1)
  - loop 1: find if 1 items sum >= s
  - loop 2: find if 2 items sum >= s
  - ...loop numsSize: fine if numsSize  items sum >= s
  
- apporach 2: T:O(n), S:O(1)
  - go through each items, sum each items and find if sum >= s
  - if found => try to find least fit len by deletnig front item in the sum
    and then keep going through left items to find if the sum of --least_len >= s

- apporach 3: two pointers, T:O(n), S:O(1)

*/

//apporach 2: T:O(n), S:O(1)
int minSubArrayLen(int s, int* nums, int numsSize) {
    int sum_len=0;
    int sum=0;
    int ret=0;
    
    for(int i=0;i<numsSize;i++){
        if(ret==0) sum_len++;
        else sum -= nums[i-sum_len];
        
        sum += nums[i];
        while(sum>=s){
            ret = sum_len;
            sum_len--;
            sum -= nums[i-sum_len];
        }
    }
    
    return ret;
}