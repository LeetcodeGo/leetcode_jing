/*************************************************************************************** 
Source : https://leetcode.com/problems/array-partition-i/description/
Author : Jing Kuo

Description:
    Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example:
    Input: [1,4,3,2]
    Output: 4
    Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Complexity:
    Time:O()
    Space:O()

Beats: 100% 

Approach: 
    1: O(nlogn),O(1), sorting then summing
    2: O(n),O(20001), add items into bucket
***************************************************************************************/

//apporach 1: O(nlogn),O(1), sorting then summing
/*int comp(int *a,int *b){
    return *a-*b;
}

int arrayPairSum(int* nums, int numsSize) {
    //TBA: if(nums==NULL) return 0;
    int sum=0;
    
    qsort(nums,numsSize,sizeof(int),comp);
    
    for(int i=0;i<numsSize;i+=2){
        sum+=nums[i];
    }
    
    return sum;
}*/

//apporach 2: O(n),O(20001), add items into bucket
//search bucket, if cnt>0, sum the bucket items
int arrayPairSum(int* nums, int numsSize) {
    //TBA: if(nums==NULL) return 0;
    int sum=0;
    int bucket[20001]={0};
    bool IsMin=true;
    int idx=0;
    
    for(int i=0;i<numsSize;i++){
        bucket[nums[i]+10000]+=1;
    }
    
    /*trade off:may add numsSize checking
     increase computing but decrease loop cnt*/
    while(idx<=20000){
        if (bucket[idx]==0){
            idx++;
            continue;
        }else{
            /*if (IsMin){
                sum+=(idx-10000)*((bucket[idx]+1)/2);
            }else{
                sum+=(idx-10000)*((bucket[idx])/2);
            }
            replaced with below sentence*/
            sum+=(idx-10000)*((bucket[idx]+(unsigned int)IsMin)/2);
            if((bucket[idx]&1)==1) IsMin=!IsMin; 
            idx++;
            /* less efficient
            if (IsMin){
                sum+=(idx-10000)*((bucket[idx]+1)/2);
                if((bucket[idx]&1)==1) IsMin=false;
                //bucket[idx]=0; can skip this
                idx++;
            }else{
                bucket[idx]--;
                IsMin=true;
            }*/
        }
    }

    return sum;
}