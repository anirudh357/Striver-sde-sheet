// Link:- https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
         // Hashmap Approach
//          unordered_set<ListNode *> s;
//          while(head!=NULL)
//          {
//              if(s.find(head)!=s.end()) return head;
//              s.insert(head);
//              head=head->next;
             
//          }   
//         return NULL;
        
        // slow and fast pointer Approach
        if(head==NULL || head->next==NULL) 
            return NULL;
        
        
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *entry=head;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {    
            while(slow!=entry)
             {
                slow=slow->next;
                entry=entry->next;
             }    
             return slow;
            }    
        }
        return NULL;
    }
};