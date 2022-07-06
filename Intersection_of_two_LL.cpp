// Link:-https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    // Optimized Approach 
    if(headA==NULL || headB==NULL) return NULL;
    
    ListNode *a = headA;
    ListNode *b = headB;
    
    while(a!=b)
    {
        a=a==NULL? headB:a->next;
        b=b==NULL? b=headA:b->next;
    }    return a;
}
};