/*
 Given a singly linked list, determine if it is a palindrome.
 
 Example 1:
 
 Input: 1->2
 Output: false
 Example 2:
 
 Input: 1->2->2->1
 Output: true
 Follow up:
 Could you do it in O(n) time and O(1) space?
 */

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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        vector<int> v;
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head=head->next;
        }
        
        for(int p1=0, p2=v.size()-1; p1 < p2; p1++, p2--)
            if(v[p1] != v[p2])
                return false;
        
        return true;
    }
};
