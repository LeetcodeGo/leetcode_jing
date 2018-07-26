/*************************************************************************************** 
Source : 
Author : Jing Kuo

Description:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

Example:
    Input: ["flower","flow","flight"]
    Output: "fl"

    Input: ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

Complexity:
    Time:O(n)
    Space:O(n)

Beats: 100% 

Approach: 

***************************************************************************************/
//O(n),O(n)
//comparing each row[idx], if all the same -> idx++
char* longestCommonPrefix(char** strs, int strsSize) {
    char *retStr;
    int idx=0,row=1;
    
    //if (strs==NULL) return NULL;
    if (strsSize<=1) return &strs[0][0]; 

    while((strs[0][idx]!='\0')&&(strs[0][idx]==strs[row][idx])){
        if(row==(strsSize-1)){
            row=1;
            idx++; 
        }else{
            row++;
        }
    }
    
    //can directly return &retStr[0][0] + modifed '\0'
    //but it may cause mem leak, so using malloc for safe
    retStr = malloc(sizeof(char)*(idx+1));  
    memcpy(retStr,&strs[0][0],idx+1);
    retStr[idx]='\0';
    return retStr;
}

//care SP:["flower","flower","flower"]