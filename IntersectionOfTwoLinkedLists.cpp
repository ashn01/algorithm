/*
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 Output: Reference of the node with value = 8
 Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i=0;
        for(auto a = headA; a != nullptr; i++)
            a=a->next;
        for(auto a = headB; a != nullptr; i--)
            a=a->next;
        
        ListNode *p1=headA, *p2=headB;
        for(;i>0;--i)
            p1=p1->next;
        for(;i<0;++i)
            p2=p2->next;
        
        while(p1!=nullptr)
        {
            if(p1 == p2)
                return p1;
            p1=p1->next;
            p2=p2->next;
        }
        
        return nullptr;
    }
};
