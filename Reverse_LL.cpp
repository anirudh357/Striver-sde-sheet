//Link :- https://leetcode.com/problems/reverse-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Brute Force Approach - 3 pointers approach
//         ListNode *prev_p=NULL;
//         ListNode *curr_p=head;
//         ListNode *next_p;
        
//         while(curr_p)
//         {
//             next_p=curr_p->next;
//             curr_p->next=prev_p;
            
//             prev_p=curr_p;
//             curr_p=next_p;
//         }    
        
//         head=prev_p;
//         return head;
        
        // Optimized Solution - Recursive - Dummy Node
//         ListNode *newHead = NULL;
//         while(head!=NULL)
//         {
//             ListNode *next=head->next;
//             head->next=newHead;
//             newHead=head;
//             head=next;
            
//         }    
//         return newHead;
        
        // Recursion
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *nnode=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return nnode;
    }
};