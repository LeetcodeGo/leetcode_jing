/*************************************************************************************** 
Source : https://leetcode.com/problems/diagonal-traverse/description/
Author : Jing Kuo

Description:
    Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.   

Example:
    Input:
    [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
    ]
    Output:  [1,2,4,7,5,3,6,8,9]

Complexity:
    Time:O(n)
    Space:O(n)

Beats: 100% 

Approach: 1  BGo through matrix by right order
          2. Go through matrix by each row, calculating target write address
***************************************************************************************/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//approach 1
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    if ( (matrixRowSize==0)&&(matrixColSize=0) ){
        *returnSize=0;
        return NULL;
    }
    
    int *ret = NULL; 
    int retIdx = 0;
    bool isEvenSkew=true;
    int x=0,y=0;
        
    *returnSize = matrixRowSize*matrixColSize;
    ret = malloc(sizeof(int)*(*returnSize));

    while(retIdx<*returnSize){
        ret[retIdx++]=matrix[x][y];
        if(isEvenSkew){
            if(y==(matrixColSize-1)){
                x++;
                isEvenSkew=!isEvenSkew;
            }else if(x==0){
                y++;
                isEvenSkew=!isEvenSkew;
            }else{
                x--;
                y++;
            }
        }else{
            if(x==(matrixRowSize-1)){
                y++;
                isEvenSkew=!isEvenSkew;
            }else if(y==0){
                x++;
                isEvenSkew=!isEvenSkew;
            }else{
                y--;
                x++; 
            }
        }
    }

    return ret;  
}

// approach 1. less in-efficient way, go thrpugh complete square matrix
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    if ( (matrixRowSize==0)&&(matrixColSize=0) ){
        *returnSize=0;
        return NULL;
    }
    
    int *ret = NULL; 
    int retIdx = 0;
    int SkewRowNum = 0;
    bool isEvenSkew=true;
    int i;
        
    *returnSize = matrixRowSize*matrixColSize;
    ret = malloc(sizeof(int)*(*returnSize));

    for(SkewRowNum=0;SkewRowNum<(matrixRowSize+matrixColSize-1);SkewRowNum++){  
        for(i=0;i<=SkewRowNum;i++){  
            if (isEvenSkew){
                if( (i<matrixColSize) && ((SkewRowNum-i)<matrixRowSize) ){
                    ret[retIdx++]=matrix[SkewRowNum-i][i];
                }
            }else{
                if( (i<matrixRowSize) && ((SkewRowNum-i)<matrixColSize) ){
                    ret[retIdx++]=matrix[i][SkewRowNum-i];
                }
            } 
        }
        
        isEvenSkew=!isEvenSkew;
    }

    return ret;
    
}


// Approach 2, has bug, too complaticed, bad solution
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    if ( (matrixRowSize==0)&&(matrixColSize=0) ){
        *returnSize=0;
        return NULL;
    }
    
    int *ret = NULL; 
    int retIdx;
    int sumInRow;
    int lackNumsSum;
    int biasInRow;
    int baseIdx;
    
    *returnSize = matrixRowSize*matrixColSize;
    ret = malloc(sizeof(int)*(*returnSize));
    
    printf("matrixRowSize:%d, matrixColSize:%d \n",matrixRowSize,matrixColSize);
    
    for(int x=0;x<matrixRowSize;x++){
        for(int y=0;y<matrixColSize;y++){
            sumInRow = x + y;
            lackNumsSum=0;
            if(sumInRow>matrixRowSize) lackNumsSum += (sumInRow-matrixRowSize)*(sumInRow-matrixRowSize+1)/2;  
            if(sumInRow>matrixColSize) lackNumsSum += (sumInRow-matrixColSize)*(sumInRow-matrixColSize+1)/2;  
            
            if ((sumInRow&1)==1){ //odd
                if(sumInRow>=matrixColSize) biasInRow = x  - (sumInRow-matrixColSize+1);
                else biasInRow = x;
            }else{ //even
                if(sumInRow>=matrixRowSize) biasInRow = y  - (sumInRow-matrixRowSize+1);
                else biasInRow = y;
            }
            
            baseIdx= (sumInRow+1)*(sumInRow)/2;
                
            retIdx= baseIdx - lackNumsSum + biasInRow;
            printf("%d %d %d\n",baseIdx,lackNumsSum,biasInRow);
            printf("%d <= (%d %d)\n\n",retIdx,x,y);
            ret[retIdx]=matrix[x][y];
            
            
        }
    }
    
    return ret;
    
}