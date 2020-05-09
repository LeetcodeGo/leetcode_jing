/*************************************************************************************** 
Source : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
Author : Jing Kuo

Description:
    Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example:
    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

Complexity:
    Time:O()
    Space:O()

Beats: 100% 

Approach: 

***************************************************************************************/
//T:O(n), S:O(1)
void str_inv(char* s,int len){
    char tmp;
    for(int i=0,j=len-1;i<j;i++,j--){
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

char* reverseWords(char* s) {
    if(s==NULL){
        return NULL;
    }
    int idx=0;
    int inv_start_idx=0;
    bool word_detect=false;
    
    while(s[idx]!='\0'){
        if(s[idx]==' '){
            if(inv_start_idx!=idx) str_inv(&s[inv_start_idx],idx-inv_start_idx);
            inv_start_idx=idx+1;
        }
        idx++;
    }
    
    if(inv_start_idx!=idx) str_inv(&s[inv_start_idx],idx-inv_start_idx);
    
    return s;
}