// ID: 328

// Description:
// Given a singly linked list, group all odd nodes together followed by the even nodes. 
// Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example 1:

// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL
// Example 2:

// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL
// Note:

// The relative order inside both the even and odd groups should remain as it was in the input.
// The first node is considered odd, the second node even and so on ...

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        ListNode* tail = head;
        while(pre->next->next && cur->next->next) {
            cur = cur->next->next;
            pre = pre->next->next;
            // insert odd node
            ListNode* tmp = tail->next;
            tail->next = cur;
            pre->next = cur->next;
            cur->next = tmp;
            
            // swap cur and pre
            tail = cur;
            cur = pre;
            pre = tail;
            while (pre->next != cur) pre = pre->next;
        }
        return head;
    }
};

