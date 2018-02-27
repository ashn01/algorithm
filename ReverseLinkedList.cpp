//https://leetcode.com/problems/reverse-linked-list/description/
//Reverse a singly linked list.

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
        ListNode* node;
        ListNode* temp = nullptr;
        while(head)
        {
            node = head;
            head = head->next;
            node->next = temp;
            temp = node;
        }
        return node; 
    }
};


/// 1  -   2 -  3  -  4