/*************************************************************************************** 
Source : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Author : Jing Kuo

Description:
    Write a program to find the node at which the intersection of two singly linked lists begins.
    For example, the following two linked lists:
    A:     a1 → a2
                    ↘
                        c1 → c2 → c3
                    ↗            
    B:     b1 → b2 → b3
    begin to intersect at node c1.

Beats: 100% 
***************************************************************************************/

/*
n dentes the len of A, m denotes the len of B

- Solution 1, Brute-force search
  1. Complexity: time:O(nm), space:O(1)
  2. Description: 
     Go through linklist A. For each node "N" in A linkist, check is there a same node in linklist B.
     
- Solution 2, Hash
  1. Complexity: time:O(n+m), space:O(k)
                 k denotes the space requirement of the hash table
  2. Description:
     Go through linklist A. Push the address of each node in A into the the hash table.
     Go through linklist B. Push the address of each node in B into the the hash table.
     When going throug link list B, if there is a same node in the hash, it means this node is the
     intersection node. If there is no such node,  it means there is no intersection node.
     
- Solution 3, Concatenate
  1. Complexity: time:O(n+m), space:O(1)
  2. Description:
     EX: Link list A: --===
         Link list B: -----===
         (- denotes different node in A and B. = denotes the same node in A and B)
         
         A': Cancatenate B to A:--=== -----===
         B': Cancatenate A to B:-----=== --===
         
     Key: Go through linklist A' and B' in a same time. Eventually, a same node will be meet.
          If the node found in A' equal the node found in B', two situations happened:
          a. If there is a intersection node:
             This node is the first intersaction node. 
          b. If there is no intersection node:
             This node is the NULL node.
             Note that the len of A' and B' is the same. 
             So they will go to NULL node in a same time when going through to the end of A' and B'.

- Following is the solution 3 in C code.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// - Solution 3, Concatenate
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *A = headA, *B = headB;
    
    while (A != B) {
        if (A == NULL) A = headB;
        else           A = A->next;
        
        if (B == NULL) B = headA;
        else           B = B->next;
        
    }

    return A;
}