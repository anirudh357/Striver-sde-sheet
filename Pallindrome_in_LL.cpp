class Solution {
public:
    ListNode* reverseList(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }    
        slow->next=reverseList(slow->next);
        slow=slow->next;
        
        
        while(slow!=NULL){
            
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};