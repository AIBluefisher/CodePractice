// ID: 148

// Description:
// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

// Solution:
// Merge sort

// 1.
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = nullptr, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pre->next = nullptr;
        ListNode* l = sortList(head);
        ListNode* r = sortList(slow);
        return merge(l, r);
    }
    
    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* l = new ListNode(-1), *r = l;
        while(p && q) {
            if(p->val < q->val) {
                r->next = p;
                p = p->next;
            }
            else {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }
        r->next = p ? p : q;
        return l->next;
    } 
};

// 2. more concise code
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = nullptr, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pre->next = nullptr;
        ListNode* l = sortList(head);
        ListNode* r = sortList(slow);
        return merge(l, r);
    }
    
    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* l = new ListNode(-1), *r = l;
        while(p && q) {
            ListNode*& tmp = (p->val < q->val) ? p : q;
            r->next = tmp;
            r = r->next;
            tmp = tmp->next;
        }
        r->next = p ? p : q;
        return l->next;
    } 
};