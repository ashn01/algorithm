//https://leetcode.com/problems/merge-two-sorted-lists/description/
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4

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
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* ret;
        if(l1 -> val < l2 -> val)
        {
            ret = l1;
            l1 = l1->next;
        }
        else
        {
            ret = l2;
            l2 = l2->next;
        }
        ListNode* temp=ret;
        int cnt=0;
        while(true)
        {
            if(l1 && l2)
                if(l1->val < l2->val)
                {
                    temp->next = l1;
                    l1=l1->next;
                }
                else
                {
                    temp->next = l2;
                    l2=l2->next;
                }
            else if(!l1)
            {
                temp->next = l2;
                break;
            }
            else if(!l2)
            {
                temp->next = l1;
                break;
            }
            temp = temp->next;
        }
        return ret;
    }
};
