/*************************************************************************************** 
Source : https://leetcode.com/problems/reverse-string/description/
Author : Jing 
Date   : 2018/6/6
 
Description:
  Write a function that takes a string as input and returns the string reversed.

Example:
  Given s = "hello", return "olleh".

Complexity:
    Time:O(n)
    Space:O(1)
***************************************************************************************/
char* reverseString(char* s) {
     int l = 0;
     int r = strlen(s)-1;
     char tmp;
     
     //TBA: if (s==NULL) return NULL;
     while(l<r)
     {
         tmp = s[l];
         s[l] = s[r];
         s[r] = tmp;
         l++;
         r--;
     }
 
     return s;
}