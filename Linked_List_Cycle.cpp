//Link :- https://leetcode.com/problems/linked-list-cycle/submissions/
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
        // Hash Table Approach
//         unordered_set<ListNode*> hashTable;
//         while(head!=NULL)
//         {
//             if(hashTable.find(head)!=hashTable.end()) return true;
//             hashTable.insert(head);
//             head=head->next;
            
//         }   
//         return head;
        
        // Slow and Fast Approach
        if(head==NULL || head->next==NULL) return false;
        
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast) return true;
        
        }
        return false;
        
    }
};