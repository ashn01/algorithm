//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

static vector<string> strs = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return vector<string>{};
}(); 
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head)
        {
            if(head->next)
            {
                if(head->val == head->next->val)
                {
                    ListNode* temp = head->next->next;
                    delete head->next;
                    head->next = temp;
                    deleteDuplicates(head);
                }
                else
                    deleteDuplicates(head->next);
            }
        }
        return head;
    }
};
