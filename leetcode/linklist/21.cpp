// ID: 21

// Description:
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l = new ListNode(-1), *r = l;
        ListNode *p = l1, *q = l2;
        while(p && q) {
            ListNode *&tmp = (p->val < q->val) ? p : q;
            r->next = tmp;
            r = tmp;
            tmp = tmp->next;
        }
        r->next = p ? p : q;
        return l->next;
    }
};