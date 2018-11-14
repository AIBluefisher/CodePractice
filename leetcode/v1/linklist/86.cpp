// ID: 86

// Description:
// Given a linked list and a value x, partition it such that all nodes 
// less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

// Solution:
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        // r points to the last element that less than x 
        // come before nodes greater than or equal to x.
        ListNode* r = dummy;    
        while(r->next && r->next->val < x) r = r->next;
        
        ListNode* pre = r, *p = pre->next;
        while(p) {
            if(p->val < x) {
                pre->next = p->next;
                p->next = r->next;
                r->next = p;
                r = p;
            }
            else pre = p;
            p = pre->next;
        }
        return dummy->next;
    }
};