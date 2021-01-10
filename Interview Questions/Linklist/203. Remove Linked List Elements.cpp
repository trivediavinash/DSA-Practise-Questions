/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

1.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       
        if (head==NULL){
            return head;
        }
        while(head!=NULL and head->val==val){    // consider case like 1 1 1 3 4 val =1
            head=head->next;
        }
        ListNode* curr =head;
        ListNode* prev =NULL;
        while(curr!=NULL){
            if(curr->val==val){
                      
                 prev->next=curr->next;
                 curr=curr->next;
               
             
            }
            else{ 
                prev=curr;
                curr=curr->next;
            }
          
        }
        
        return head;
       
        
    }
};

2.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr =head;
        if (head==NULL){
            return head;
        }
       
        while(curr->next!=NULL){
            if(curr->next->val==val){
                 curr->next=curr->next->next;
             
            }
            else  curr=curr->next;
          
        }
        if (head->val==val)
            head=head->next;
        return head;
       
        
    }
};