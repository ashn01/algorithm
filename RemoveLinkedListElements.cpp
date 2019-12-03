/*
 Remove all elements from a linked list of integers that have value val.
 
 Example:
 
 Input:  1->2->6->3->4->5->6, val = 6
 Output: 1->2->3->4->5
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto p = head;
        ListNode* prev=nullptr;
        
        while(p!=nullptr)
        {
            if(p->val == val)
            {
                if(prev == nullptr)
                    head = p->next;
                else
                    prev->next = p->next;
            }
            else
                prev = p;
            p=p->next;
        }
        
        return head;
    }
};
