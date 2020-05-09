/*************************************************************************************** 
Source : https://leetcode.com/problems/implement-strstr/description/
Author : Jing Kuo

Description:
    Implement strStr().
    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example:
    Input: haystack = "hello", needle = "ll"
    Output: 2

Complexity:
    Time:O(n*m)
    Space:O(1)

Beats: 100% 

Approach: 1. go through haystack and comparing
          2. KMP, O(n+m),O(m)
          3. BM (Boyer-Moore) faster than KMP

***************************************************************************************/
//1:O(m*n), O(1)
int strStr(char* haystack, char* needle) {
    int strlenHaystack,strlenNeedle,cmpIdx;

    if ((haystack==NULL)||(needle==NULL)) return 0;
    
    strlenHaystack=strlen(haystack);
    strlenNeedle=strlen(needle);
    if(strlenNeedle==0) return 0;
    
    //if (strlenNeedle > strlenHaystack) return -1;  for loop has done this
    
    for(int idx=0;idx<=(strlenHaystack-strlenNeedle);idx++){
        /* can improved below by while
        if (memcmp(&haystack[idx],needle,strlenNeedle)==0) 
        or
        for(cmpIdx=0;cmpIdx<strlenNeedle;cmpIdx++){
            if (haystack[idx+cmpIdx]!=needle[cmpIdx]) break;
        }
        if(cmpIdx==strlenNeedle) return idx;*/
        cmpIdx=0;
        while(true){
            if (needle[cmpIdx]=='\0') return idx;
            if (haystack[idx+cmpIdx]!=needle[cmpIdx]) break;
            cmpIdx++;
        }
    }
    return -1;
}

//2:KMP (Knuth–Morris–Pratt ), O(n+m),O(m)
//3.BM (Boyer-Moore) faster than KMP