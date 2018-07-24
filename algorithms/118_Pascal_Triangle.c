/*************************************************************************************** 
Source : https://leetcode.com/problems/pascals-triangle/description/
Author : Jing Kuo

Description:
    Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:
    Input: 5
    Output:
    [
        [1],
        [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]
    ]

Complexity:
    Time:O(n^2)
    Space:O(n^2)

Beats: 100% 

Approach: 

***************************************************************************************/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **ret;
    
    if(numRows==0) return NULL;
    
    ret = (int**)malloc(sizeof(int*)*numRows);
    *columnSizes = (int*)malloc(sizeof(int)*numRows);
    
    for(int row=0;row<numRows;row++){
        (*columnSizes)[row]=row+1;
        ret[row]=malloc(sizeof(int)*(row+1));
        ret[row][0]=1;
        ret[row][row]=1;
        
        for(int idxInRow=1;idxInRow<row;idxInRow++){
            ret[row][idxInRow]=ret[row-1][idxInRow-1]+ret[row-1][idxInRow];
        }    
    }
    
    return ret;
}