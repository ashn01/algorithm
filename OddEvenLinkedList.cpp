//https://leetcode.com/problems/odd-even-linked-list/description/
//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note:
//The relative order inside both the even and odd groups should remain as it was in the input. 
//The first node is considered odd, the second node even and so on ...


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* odd;
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* tail = make(head,odd);
        make(head->next,tail->next);
        return odd;
    }
    ListNode* make(ListNode* sub, ListNode*& ret)
    {
        if(sub == nullptr)
            return ret;
        ret = new ListNode(sub->val);
        if(sub->next != nullptr && sub->next->next != nullptr)
        {
            return make(sub->next->next,ret->next);
        }
        else
            return ret;
    }
    /*void deletion(ListNode* ohs)
    {
        if(ohs != nullptr)
        {
            if(ohs->next != nullptr)
            {
                ListNode* temp = ohs->next;
                deletion(temp);
            }
            cout << ohs->val<<endl;
            delete ohs;
            ohs= nullptr;
        }
    }
    ~Solution()
    {
        deletion(odd);
    }*/
};