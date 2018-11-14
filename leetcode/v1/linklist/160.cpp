// ID: 160

// Description:


// Solution:

// 1. use ordered_set. Time complexity: O(n), space complexity: O(n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> ls;
        ListNode *p = headA;
        while(p) {
            ls.insert(p);
            p = p->next;
        }
        p = headB;
        while(p) {
            if(ls.find(p) != ls.end()) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};

// 2. two pointers
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        if(!p || !q) return nullptr;
        
        while(p && q && p != q) {
            p = p->next;
            q = q->next;
            if(p == q) return p;
            if(!p) p = headB;
            if(!q) q = headA;
        }
        return p;
    }
};