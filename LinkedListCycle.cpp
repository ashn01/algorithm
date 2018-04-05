//https://leetcode.com/problems/linked-list-cycle/description/
//Given a linked list, determine if it has a cycle in it.
//
//Follow up:
//Can you solve it without using extra space?

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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* forward=head;
        while(head)
        {
            head=head->next;
            if(forward->next && forward->next->next)
                forward = forward->next->next;
            else
                return false;
            if(forward == head)
                return true;
        }
        return false;
    }
};
