// ID: 147

// Description:
// Sort a linked list using insertion sort.


// A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
// With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

// Algorithm of Insertion Sort:

// Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
// It repeats until no input elements remain.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = head->next, *p_pre = head;
        ListNode* dummy_head = new ListNode(INT_MIN);
        dummy_head->next = head;
        
        while(p) {
            ListNode* q = dummy_head;
            while(q != p && q->next->val <= p->val) {
                q = q->next;
            }
            if(q == p) {
                p_pre = p;
                p = p->next;
                continue;
            }
            
            p_pre->next = p->next;
            p->next = q->next;
            q->next = p;
            p = p_pre->next;
        }
        return dummy_head->next;
    }
};