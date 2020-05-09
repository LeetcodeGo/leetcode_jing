/*************************************************************************************** 
Source : https://leetcode.com/problems/pascals-triangle-ii/description/
Author : Jing Kuo

Description:
    Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
    Note that the row index starts from 0.

Example:
    Input: 3
    Output: [1,3,3,1]

Complexity:
    Time:O(k^2)
    Space:O(k)

Beats: 100% 

Approach: 

***************************************************************************************/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    
    int *ret=malloc((rowIndex+1)*sizeof(int));
   // int offset;
    *returnSize=rowIndex+1;
    
    ret[0]=1;
    
    for(int row=1;row<=rowIndex;row++){
        ret[row]=1;
        //offset=0;
        
        /* slow solution
        for(int column=1;2*column<=row;column++){
            ret[column]=ret[column-1]+ret[column]-offset;
            ret[row-column]=ret[column];
            offset=ret[column-1]-offset;
        }*/
        
        //faster
       for(int column=row-1;column>=1;column--){
            ret[column]=ret[column-1]+ret[column];
        }
    }
    
    return ret;
}