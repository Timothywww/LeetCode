/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int head_flag=1;
        ListNode* head=NULL;
        ListNode* prev = NULL;
        int carry=0;
        while(l1 || l2 || carry){
            int sum = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry = sum/10;
            ListNode* new_node =new ListNode(sum%10);
            if(head_flag==1){
                head = new_node;
                prev = head;
                head_flag=0;
            }
           else{
               prev->next = new_node;
               prev = new_node;
           }
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        
        }
        return head;
        
    }
};

/* 24ms */

/* Time complexity : O(\max(m, n))O(max(m,n)). Assume that mm and nn represents the length of l1l1 and l2l2 respectively, the algorithm above iterates at most \max(m, n)max(m,n) times.

Space complexity : O(\max(m, n))O(max(m,n)). The length of the new list is at most \max(m,n) + 1max(m,n)+1. */


/* !!!!!!
   ListNode* new_node = new ListNode(val);

   set head and prev pointer

   check carry bit at the end

   check if either list is null 
 */



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prehead = ListNode(0);
        ListNode* prev = &prehead;
        int carry=0;
        while(l1 || l2 || carry){
            int sum = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry = sum/10;
            prev->next  = new ListNode(sum%10);
            prev=prev->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        
        }
        return prehead.next;
        
    }
};

/* neat version but slower (28ms)*/