/*************************************************************************************** 
Source : https://leetcode.com/problems/palindrome-linked-list/description/
Author : Jing Kuo

Description:
    Given a singly linked list, determine if it is a palindrome.
    Example 1:

    Input: 1->2
    Output: false
    Example 2:

    Input: 1->2->2->1
    Output: true
    Follow up:
    Could you do it in O(n) time and O(1) space?

Beats: 100% 

Approach: 

***************************************************************************************/
/*
n dentes the len link list

- solution
  1. Complexity, time:O(n), space:O(1)
  2. Description:
     - Go through link list and get the len:n 
     - Reverse the front n/2 nodes in the link list
     - Then two link list can be gone through to see the node sequence is the same
       If they are the same, whicj means the list is isPalindrome
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL) return true;
    
    int size = 0;
    struct ListNode* n = head;
    bool odd;
    
    while(n != NULL) {
        n = n->next;
        size++;
    }
    
    if ((size & 1) == 1) odd = true;
    else                 odd = false;
    
    size = size/2;
    
    struct ListNode* pre_n = NULL;
    struct ListNode* next_n = NULL;
    n = head;
    
    while(size >= 1) {
        next_n = n->next;
        n->next = pre_n;
        pre_n = n;

        n = next_n;
        size--;
    }
    
    if (odd) n = n->next;
    
    while (n != NULL) {
        if (n->val != pre_n->val) return false;
        
        n = n->next;
        pre_n = pre_n->next;
    }
    
    return true;
}