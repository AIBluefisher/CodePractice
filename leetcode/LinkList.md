## 206. Reverse Linked List

**描述**：Reverse a singly linked list.

**分析**：头插法反转单链表。这里的链表不带头节点。这里给出三种不同的方法。前两种均为不带头节点的实现方法，第三种为加上头节点的实现。

**代码**：

*（1）不带头节点的实现*
```C++
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* p = head->next;
        head->next = NULL;
        ListNode* q;
        while(p != NULL)
        {
            q = p;
            p = p->next;
            q->next = head;
            head = q;
        }
        return head;
    }
};
```

```C++

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur != NULL)
        {
            prev->next = cur->next;
            cur->next = head;
            head = cur;
            cur = prev->next;
        }
        return head;
    }
};
```

*(2)带头节点的实现*
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* l = new ListNode(-1); // 带头节点
        
        ListNode* p = head;
        ListNode* q;
        while(p != NULL)
        {
            q = p->next;
            p->next = l->next;
            l->next = p;
            p = q;
        }
        
        return l->next;
    }
};
```


***


## 92. Reverse Linked List II

**描述**：Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

**分析**：同206相同，同样采用头插法反转单链表。不同的是，由于区间限制，需要注意边界情况。首先，给链表加上头节点，指向链表的第一个元素。再通过m，查找到第m个元素的前一个元素，该元素可看做新的头节点，因此，算法可以使用带头节点的反转单链表实现。

**代码**:
```C++
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* l = new ListNode(-1);
        l->next = head;
        
        ListNode* prev = l;
        for(int i = 0; i < m - 1; i++) prev = prev->next;
        
        ListNode* ph = prev;
        prev = ph->next;
        ListNode* cur = prev->next;
        for(int i = m; i < n; i++)
        {
            prev->next = cur->next;
            cur->next = ph->next;
            ph->next = cur;
            cur = prev->next;
        }
        return l->next;
    }
};
```

***

## 2. Add Two Numbers

**描述**： You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**分析**: 加法需要从低位往高位逐个相加，而链表已经是逆序的，因此只需要从头遍历两个链表中的元素并逐个相加即可。新的链表使用尾插法即可产生逆序的数字。需要注意的地方是如果使用不带头节点的指针不太好实现，因此新的链表加上了头节点。

**代码**:
```C++
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
        ListNode* l = new ListNode(-1); // 新的链表头部
        ListNode* tail = l; // 尾指针，始终指向进件链表的尾部
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;  // 进位
        while(p1 != NULL || p2 != NULL)
        {
            int v1 = (p1 == NULL ? 0 : p1->val);
            int v2 = (p2 == NULL ? 0 : p2->val);
            int tmp = v1 + v2 + carry;
            carry = tmp > 9 ? 1 : 0;
            tmp %= 10;
            ListNode* r = new ListNode(tmp);
            tail->next = r;
            tail = r;
            
            if(p1 != NULL) p1 = p1->next;
            if(p2 != NULL) p2 = p2->next;
        }
        
        if(carry)   // 最后一次加法是否产生进位，若是，则需新建节点并加入链表
        {
            ListNode* r = new ListNode(carry);
            tail->next = r;
            tail = r;
        }
        return l->next;
    }
};
```

## 203. Remove Linked List Elements

**描述**: 

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

**分析**
为了删除元素，需设置一pre指针指向当前元素的前一个元素。对于与所给值相同的元素，将pre的下一个元素指向当前元素的下一个元素即可。为了防止内存泄露，需释放当前元素。

**代码**
```C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        ListNode* l = new ListNode(-1);
        l->next = head;
        
        ListNode* pre = l;
        ListNode* cur = l->next;
        
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                pre->next = cur->next;
                delete cur;
            }
            else pre = cur;
            cur = pre->next;
        }
        return l->next;
    }
};
```

## 83. Remove Duplicates from Sorted List

**Difficulty**: easy

**描述**

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3

**分析**

无

**代码**
```C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != NULL)
        {
            if(pre->val != cur->val)
            {
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        pre->next = cur;
        return head;
    }
};
```


## 445. Add Two Numbers II

**Difficulty**: Medium

**描述**

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

**分析**

若可以反转链表，那么剩下的做法就和Add Two Numbers一样。
若不能反转链表，暂无思路。


**代码**
```C++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseListNode(l1);
        ListNode* rl2 = reverseListNode(l2);
        
        ListNode* l = new ListNode(-1);
        ListNode* p1 = rl1;
        ListNode* p2 = rl2;
        int carry = 0;
        
        while(p1 != NULL || p2 != NULL)
        {
            int v1 = (p1 == NULL ? 0 : p1->val);
            int v2 = (p2 == NULL ? 0 : p2->val);
            int val = v1 + v2 + carry;
            carry = val > 9 ? 1 : 0;
            val %= 10;
            ListNode* tmp = new ListNode(val);
            tmp->next = l->next;
            l->next = tmp;
            if(p1 != NULL) p1 = p1->next;
            if(p2 != NULL) p2 = p2->next;
        }
        
        if(carry)
        {
            ListNode* tmp = new ListNode(1);
            tmp->next = l->next;
            l->next = tmp;
        }
        return l->next;
    }
    
private:
    ListNode* reverseListNode(ListNode* l)
    {
        if(l == NULL || l->next == NULL) return l;
        
        ListNode* p = l->next;
        l->next = NULL;
        ListNode* q;
        while(p != NULL)
        {
            q = p;
            p = p->next;
            q->next = l;
            l = q;
        }
        return l;
    }
};
```
## 19. Remove Nth Node From End of List

**Difficulty**: Medium

**描述**

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

**分析**

(1) 如果要求不限制只遍历一次，那么一种简单的实现为先遍历一遍链表，得到链表的长度len；然后第二次遍历，走len - n步，将下一个元素删除即可。

(2) 但是要求在一次遍历中完成.那么可以设置两个指针pre、cur，cur和pre的距离为n + 1，那么当cur达到链表的末尾时（指向为NULL的指针），pre指向的元素为倒数第n个元素的前一个元素，这时将pre的下一个元素删除即可；实现时，先增加头节点，让pre指向头节点，cur指向头节点的下一个元素（第一个元素），然后先让cur先走n步，使得pre和cur的距离为n + 1，最后同步增加pre和cur，当cur达到链表末尾时循环结束。

**代码**
```C++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l = new ListNode(-1);
        l->next = head;
        
        ListNode* pre = l;
        ListNode* cur = l->next;
        int dis = 0;
        while(dis++ < n) cur = cur->next;
        while(cur != NULL)
        {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        return l->next;
    }
};
```


## 21. Merge Two Sorted Lists

**Difficulty**: Easy

**描述**

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

**分析**

合并两个有序的链表。只需要对两个链表从头开始比较即可。

**代码**

```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(-1);
        ListNode* r = l;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val < p2->val)
            {
                r->next = p1;
                r = p1;
                p1 = p1->next;
            }
            else
            {
                r->next = p2;
                r = p2;
                p2 = p2->next;
            }
        }
        if(p1 == NULL)
        {
            while(p2 != NULL)
            {
                r->next = p2;
                r = p2;
                p2 = p2->next;
            }
        }
        if(p2 == NULL)
        {
            while(p1 != NULL)
            {
                r->next = p1;
                r = p1;
                p1 = p1->next;
            }
        }
        return l->next;
    }
};
```

## 237. Delete Node in a Linked List

**Difficulty**: Easy

**描述**

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

**分析**

刚开始看这题的时候还摸不着头脑，不明白什么意思。但是仔细一想，即使不给出需要用来删除的链表也是可以将节点删除的。由于被删除节点不是最后一个节点，因此只要将待删除节点与下一个节点交换，再将next指针指向下一个节点的下一个节点即可。

**代码**

```C++
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete tmp;
    }
};
```

## 141. Linked List Cycle

**Difficulty**: Easy

**描述**

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

**分析**

要求为不使用额外的空间。那么可以设置两个指针，一个每次走一步，另一个每次走两步，当走得更快的指针追上慢的那个指针时，说明存在环。

**代码**

```C++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
```

## 24. Swap Nodes in Pairs

**Difficulty**: Medium

**描述** 

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


**分析**

交换两个相邻节点，不能更改节点的值，因此只能修改next指针。可设置三个指针，一个为头节点，一个指向要交换的第一个元素，一个指向要交换的第二个元素，交换完之后向下移动指针即可。

**代码**

```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode* l = new ListNode (-1);
        l->next = head;
        ListNode* ph = l;
        ListNode* pre = l->next;
        ListNode* cur = pre->next;
        while(pre != NULL && cur != NULL)
        {
            ListNode* tmp = cur->next;
            cur->next = ph->next;
            ph->next = cur;
            pre->next = tmp;
            ph = pre;
            pre = ph->next;
            if(pre != NULL) cur = pre->next;
        }
        return l->next;
    }
};
```


## 82. Remove Duplicates from Sorted List II

**Difficulty**: Medium

**描述** 

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


**分析**

需要将有相同元素的节点全部删除。首先设置头节点指向第一个元素，然后设置一个pre指针和一个cur指针，若pre->val和cur->val相同，则将cur设为cur->next一直到pre->val != cur->val。再设置一个伪头节点ph，ph->next永远指向pre。当pre指针指向的元素值和cur指针指向元素的值不同时，修改ph。这里要分两种情况考虑，一种是pre->val和cur->val不同，但是pre和val之间没有其他节点；一种时pre->val和cur->val不同，但是pre和val之间存在其他节点(这些节点的值都相同)。只要分这两种情况修改指针即可。

**代码**

```C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* l = new ListNode(-1);
        l->next = head;
        ListNode* ph = l;
        ListNode* pre = l->next;
        ListNode* cur = pre->next;
        
        int count = 1;
        while(cur != NULL)
        {
            if(pre->val != cur->val)
            {
                if(count > 1) ph->next = cur;
                else ph = pre;
                pre = cur;
                cur = pre->next;
                count = 1;
            }
            else 
            {
                count++;
                cur = cur->next;
            }
        }
        if(count > 1) ph->next = NULL;
        return l->next;
    }
};
```

## 234. Palindrome Linked List

**Difficulty**: easy

**描述**

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

**分析**

判断一个单链表是否回文．如果是数组的话，O(n)和O(1)的时间复杂度很容易就能想到，分别从头和尾部开始比较即可．但是单链表只能单向遍历．这样的话，一种很直接的思路就是头插法反转单链表得到一个新链表，再和原链表比较，时间复杂度和空间复杂度均为O(n)．
目前思路还没想到只需使用O(1)的空间复杂度的．

**代码**
```C++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* rhead = reverseList(head);
        ListNode* p = rhead;
        ListNode* q = head;
        while(q != NULL)
        {
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* l = new ListNode(-1);
        ListNode* p = head;
        while(p != NULL)
        {
            ListNode* tmp = new ListNode(p->val);
            tmp->next = l->next;
            l->next = tmp;
            p = p->next;
        }
        return l->next;
    }
};
```