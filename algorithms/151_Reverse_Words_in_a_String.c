/*************************************************************************************** 
Source : 
Author : Jing Kuo

Description:
    Given an input string, reverse the string word by word.

Example:
    Input: "the sky is blue",
    Output: "blue is sky the".

Complexity:
    Time:O()
    Space:O()

Beats: 100% 

Approach: 

***************************************************************************************/
/*
Soltuon 1: T:O(n),S:T(n)
- allocate array with same size of input string
- go through input string, write each word beggining from the end of the allocate string


Soltuon 2: T:O(n),S:T(1)
- reverse each word 
- reverse whole string

*/

void(char *start,char *end,char *s){
    char tmp;
    
    while (s<start)&&(start<=end){
        *s=*end;
        *end=' ';
        s++;
        end--;
    }
    
    for(;start<end;start++,end--){
        tmp = *start;
        *start = *end;
        *end=tmp;
    }
}


void reverseWords(char *s) {
    char *sCP=s;
    char *sWriteIdx=s;
    char *inverseWriteStart, *inverseWriteEnd;
    bool wordDetect=false;
    
    if (s==NULL) return;
    
    while(*sCP!='\0'){
        if (wordDetect){
            if(*sCP==' '){
                
                inverseWriteEnd=sCP-1;
                writeInverse(inverseWriteStart,inverseWriteEnd,sWriteIdx);
                sWriteIdx+=(inverseWriteEnd-inverseWriteStart)+1;
                *sWriteIdx=' ';
                sWriteIdx++;
                wordDetect=false;
            }
        }else{
            if(*sCP!=' '){
                inverseWriteStart = sCP;
                wordDetect=true;
            }
        }
        
        sCP++;
    }
    
    while(*(--sCP)!='_'){}
    
    writeInverse(s,sCP,s);
    sCP++;
    *sCP ='\0';
    
}