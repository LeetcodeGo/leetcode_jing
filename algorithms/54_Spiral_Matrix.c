/*************************************************************************************** 
Source : https://leetcode.com/problems/spiral-matrix/description/
Author : Jing Kuo

Description:
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:
    Input:
    [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9,10,11,12]
    ]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Complexity:
    Time:O(m*n)
    Space:O(m*n)

Beats: 100% 

Approach: 

***************************************************************************************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//To be improved: a 4-state variable to replace isIncreas & isRow
//Another large modified approach: expand the 4 state case to 4 loop, which may has faster speed.
//Because, it doesn't need to compare state in each write
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if( (matrixRowSize==0)&&(matrixColSize==0) ) return NULL;

    int circleCnt=0;
    bool isIncreas=true;
    bool isRow =true;
    int retIdx=0;
    int *ret=malloc(sizeof(int)*(matrixRowSize*matrixColSize));
    int x=0,y=0;
     
    while(retIdx< (matrixRowSize*matrixColSize)){
        ret[retIdx++]=matrix[x][y];
        
        if(isRow){
            if (isIncreas){
                if (y==(matrixColSize-circleCnt-1)){
                    isRow=false;
                    x++;
                }else{
                    y++;
                }    
            }else{
                if(y==circleCnt){
                    isRow=false;
                    x--;
                }else{
                    y--;
                }
            }
        }else{
            if (isIncreas){
                if (x==(matrixRowSize-circleCnt-1)){
                    isRow=true;
                    isIncreas=false;
                    y--;
                }else{
                    x++;
                }    
            }else{
                if(x==(circleCnt+1)){
                    isRow=true;
                    y++;
                    circleCnt++;
                    isIncreas=true;
                }else{
                    x--;
                }
            }
        }
    }
    
    return ret;
}


//a good improved ex in Java
class Solution {
    public List < Integer > spiralOrder(int[][] matrix) {
        List ans = new ArrayList();
        if (matrix.length == 0)
            return ans;
        int r1 = 0, r2 = matrix.length - 1;
        int c1 = 0, c2 = matrix[0].length - 1;
        while (r1 <= r2 && c1 <= c2) { //while(1)
        
            for (int c = c1; c <= c2; c++) ans.add(matrix[r1][c]);
            //if idx==maxcnt break

            for (int r = r1 + 1; r <= r2; r++) ans.add(matrix[r][c2]);
           //if idx==maxcnt break

            if (r1 < r2){
                for (int c = c2 - 1; c > c1; c--) ans.add(matrix[r2][c]);
                //take off (r1<r2) add => if idx==maxcnt break
            }
            
            if (c1 < c2){
                for (int r = r2; r > r1; r--) ans.add(matrix[r][c1]);
                 //take off (c1<c2) add => if idx==maxcnt break
            }
     
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
}